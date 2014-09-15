#include "redis.hh"
#include <unistd.h>

QString Redis::getAuth() const
{
    return auth;
}

void Redis::setAuth(const QString &value)
{
    auth = value;
}

QString Redis::getHighRequestQueue() const
{
    return highRequestQueue;
}

void Redis::setHighRequestQueue(const QString &value)
{
    highRequestQueue = value;
}

QString Redis::getLowRequestQueue() const
{
    return lowRequestQueue;
}

void Redis::setLowRequestQueue(const QString &value)
{
    lowRequestQueue = value;
}

QString Redis::getResultQueue() const
{
    return resultQueue;
}

void Redis::setResultQueue(const QString &value)
{
    resultQueue = value;
}
timeval Redis::getTimeoutVal(qint64 timeout)
{
    timeval tv;
    tv.tv_sec = timeout/1000;
    tv.tv_usec = (timeout%1000)*1000;
    return tv;
}

const char *Redis::c_str(const QString &s)
{
    return s.toStdString().c_str();
}

void Redis::debugReply(redisReply *r)
{
    if(r == NULL)
        return;

    switch(r->type)
    {
    case REDIS_REPLY_STATUS:
        LOG(DEBUG) << "debug-reply : status : " << r->str;
        break;
    case REDIS_REPLY_ERROR:
        LOG(DEBUG) << "debug-reply : error : " << r->str;
        break;
    case REDIS_REPLY_INTEGER:
        LOG(DEBUG) << "debug-reply : integer : " << r->integer;
        break;
    case REDIS_REPLY_NIL:
        LOG(DEBUG) << "debug-reply : nil";
        break;
    case REDIS_REPLY_STRING:
        LOG(DEBUG) << "debug-reply : string : " << r->str;
        break;
    case REDIS_REPLY_ARRAY:
        LOG(DEBUG) << "debug-reply : array(" << r->elements << ")";
    }
}

Request *Redis::getHighRequest()
{
    return getRequestData(highRequestQueue);
}

Request *Redis::getLowRequest()
{
    return getRequestData(lowRequestQueue);
}

Request *Redis::getRequestData(QString &queue)
{
    if(!connected())
        return NULL;

    Request *request = NULL;
    redisReply *reply = (redisReply*)redisCommand(conn, "LPOP %s", c_str(queue));
    if(reply == NULL)
    {
        LOG(DEBUG) << "empty queue : " << queue;
    }

    debugReply(reply);

    if(reply->type != REDIS_REPLY_STRING && reply->type != REDIS_REPLY_NIL)
    {
        LOG(DEBUG) << "Redis : invalid queue data";
        freeReplyObject(reply);
        freeReplyObject(reply);
        return NULL;
    }

    if(reply->type == REDIS_REPLY_NIL)
    {
        freeReplyObject(reply);
        return NULL;
    }

    request = Request::fromJson(reply->str);
    freeReplyObject(reply);
    return request;
}

bool Redis::authorize()
{
    redisReply *reply = (redisReply*)redisCommand(conn, "AUTH %s", c_str(auth));
    if(reply == NULL)
    {
        LOG(DEBUG) << "Redis : Auth failed, " << conn->errstr;
        return false;
    }
    debugReply(reply);
    freeReplyObject(reply);
    return true;
}

Redis::Redis(const char *ip, int port, const char *auth)
    : failConnectCount(0),
      ip(ip),
      port(port),
      auth(auth),
      highRequestQueue(HIGH_REQUEST_QUEUE),
      lowRequestQueue(LOW_REQUEST_QUEUE),
      resultQueue(RESULT_QUEUE)
{
}

Redis::~Redis()
{
    if(conn != NULL)
        redisFree(conn);
}

bool Redis::connect()
{
    if(timeout <= 0)
        conn = redisConnect(c_str(ip), port);
    else
        conn = redisConnectWithTimeout(c_str(ip), port, getTimeoutVal(timeout));

    if(conn == NULL || conn->err != 0)
    {
        LOG(DEBUG) << "Redis : cannot connect to redis server " << ip << ":" << port;
        redisFree(conn);
        conn = NULL;
        failConnectCount++;
        if(++failConnectCount > MAX_FAIL_COUNT)
        {
            LOG(FATAL) << "Cannot connect to redis, failed " << failConnectCount << " times";
            exit(-1);
        }
        sleep(1);
        return false;
    }

    if(!auth.isEmpty() && !authorize())
    {
        redisFree(conn);
        if(++failConnectCount > MAX_FAIL_COUNT)
        {
            LOG(FATAL) << "Cannot connect to redis, failed " << failConnectCount << " times";
            exit(-1);
        }
        sleep(1);
        return false;
    }

    LOG(INFO) << "Redis : connected.";
    failConnectCount = 0;
    return true;
}

bool Redis::connected()
{
    if(conn == NULL && !connect())
        return false;

    return true;
}

Request* Redis::getRequest()
{
    if(!connected())
        return NULL;

    Request *req = NULL;
    if((req = getHighRequest()) == NULL)
        if((req = getLowRequest()) == NULL)
            return NULL;
    return req;
}

qint64 Redis::getTimeout() const
{
    return timeout;
}

void Redis::setTimeout(qint64 value)
{
    timeout = value;
}
