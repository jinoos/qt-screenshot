#ifndef REDIS_HH
#define REDIS_HH

#include <QString>
#include "hiredis/hiredis.h"
#include "common.hh"
#include "request.hh"

#define HIGH_REQUEST_QUEUE  "snapshot_request_high"
#define LOW_REQUEST_QUEUE   "snapshot_request_low"
#define RESULT_QUEUE        "snapshot_result"
#define MAX_FAIL_COUNT      1000

class Request;

class Redis
{
private:
    redisContext    *conn;
    int             failConnectCount;
    QString         ip;
    int             port;
    QString         auth;
    QString         highRequestQueue;
    QString         lowRequestQueue;
    QString         resultQueue;
    qint64          timeout; // miliseconds

    timeval getTimeoutVal(qint64 timeout);
    const char * c_str(const QString &s);
    bool authorize();
    void debugReply(redisReply *r);
    Request* getHighRequest();
    Request* getLowRequest();
    Request* getRequestData(QString &queue);

public:
    Redis(const char *ip, int port, const char *auth = "");
    ~Redis();

    bool connect();
    bool connected();
    Request* getRequest();
    qint64 getTimeout() const;
    void setTimeout(qint64 value);
    QString getAuth() const;
    void setAuth(const QString &value);

    QString getHighRequestQueue() const;
    void setHighRequestQueue(const QString &value);
    QString getLowRequestQueue() const;
    void setLowRequestQueue(const QString &value);
    QString getResultQueue() const;
    void setResultQueue(const QString &value);

public slots:


signals:
};

#endif // REDIS_HH
