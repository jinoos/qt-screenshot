#include "request.hh"
#include "jansson.h"

bool Request::checkJsonMandatory(json_t *json, const char *key, json_type type)
{
    json_t *val = json_object_get(json, key);

    if(val == NULL)
    {
        qWarning("Request : json format error, missing %s", key);
        return false;
    }

    if(val->type != type)
    {
        qWarning("Request : json format error, %s is wrong type", key);
        return false;
    }

    return true;
}

bool Request::checkJsonType(json_t *json, const char *key, json_type type)
{
    json_t *val = json_object_get(json, key);

    if(val == NULL)
        return true;

    if(val->type != type)
    {
        qWarning("Request : json format error, %s is wrong type", key);
        return false;
    }

    return true;
}

const char *Request::getJsonString(json_t *json, const char *key, const char *def)
{
    json_t *val = json_object_get(json, key);

    if(val == NULL)
    {
        return def;
    }

    if(val->type != JSON_STRING)
    {
        qWarning("Request : json format error, %s is wrong type", key);
        return NULL;
    }

    return json_string_value(val);
}

qint64 Request::getJsonLong(json_t *json, const char *key, qint64 def)
{
    json_t *val = json_object_get(json, key);

    if(val == NULL)
    {
        return def;
    }

    if(val->type != JSON_INTEGER)
    {
        qWarning("Request : json format error, %s is wrong type", key);
        return 0;
    }

    return json_integer_value(val);
}

int Request::getJsonInt(json_t *json, const char *key, int def)
{
    json_t *val = json_object_get(json, key);

    if(val == NULL)
    {
        return def;
    }

    if(val->type != JSON_INTEGER)
    {
        qWarning("Request : json format error, %s is wrong type", key);
        return 0;
    }

    return (int) json_integer_value(val);
}

Request::Request()
    : format(DEFAULT_FORMAT),
      quality(DEFAULT_QUALITY),
      tileMax(DEFAULT_TILE_MAX),
      tileHeight(DEFAULT_TILE_HEIGHT)
{
}

Request::Request(qint64 p, QString &url, QString &dir, QString &prefix)
    : productNo(p),
      url(url),
      dir(dir),
      prefix(prefix),
      format(DEFAULT_FORMAT),
      quality(DEFAULT_QUALITY),
      tileMax(DEFAULT_TILE_MAX),
      tileHeight(DEFAULT_TILE_HEIGHT)
{
}

Request::Request(qint64 p, const char *url, const char *dir, const char *prefix)
    : productNo(p),
      url(url),
      dir(dir),
      prefix(prefix),
      format(DEFAULT_FORMAT),
      quality(DEFAULT_QUALITY),
      tileMax(DEFAULT_TILE_MAX),
      tileHeight(DEFAULT_TILE_HEIGHT)
{

}

Request *Request::fromJson(const char *jsonStr)
{
    if(jsonStr == NULL)
        return NULL;

    json_error_t err;
    json_t *json = json_loads(jsonStr, JSON_REJECT_DUPLICATES, &err);

    if(json == NULL)
    {
        qWarning("Request : %s in \"%s\" at line:%d", err.text, err.source, err.line);
        return NULL;
    }

    // validation
    checkJsonMandatory(json, REQ_JSON_PRODUCT_NO, JSON_INTEGER);
    checkJsonMandatory(json, REQ_JSON_URL, JSON_STRING);
    checkJsonMandatory(json, REQ_JSON_DIR, JSON_STRING);
    checkJsonMandatory(json, REQ_JSON_PREFIX, JSON_STRING);
    checkJsonMandatory(json, REQ_JSON_FORMAT, JSON_STRING);
    checkJsonType(json, REQ_JSON_QUALITY, JSON_INTEGER);
    checkJsonType(json, REQ_JSON_TILE_MAX, JSON_INTEGER);
    checkJsonType(json, REQ_JSON_TILE_HEIGHT, JSON_INTEGER);

    Request *req = new Request();

    req->productNo = getJsonLong(json, REQ_JSON_PRODUCT_NO, 0);
    req->url = getJsonString(json, REQ_JSON_URL, "");
    req->dir = getJsonString(json, REQ_JSON_DIR, "");
    req->prefix = getJsonString(json, REQ_JSON_PREFIX, "");
    req->quality = getJsonInt(json, REQ_JSON_QUALITY, DEFAULT_QUALITY);
    req->tileMax = getJsonInt(json, REQ_JSON_TILE_MAX, DEFAULT_TILE_MAX);
    req->tileHeight = getJsonInt(json, REQ_JSON_TILE_HEIGHT, DEFAULT_TILE_HEIGHT);

    return req;
}

qint64 Request::getProductNo() const
{
    return productNo;
}

void Request::setProductNo(qint64 value)
{
    productNo = value;
}

const QString& Request::getUrl() const
{
    return url;
}

void Request::setUrl(const QString &value)
{
    url = value;
}

const QString& Request::getDir() const
{
    return dir;
}

void Request::setDir(const QString &value)
{
    dir = value;
}

const QString& Request::getPrefix() const
{
    return prefix;
}

void Request::setPrefix(const QString &value)
{
    prefix = value;
}

const QString& Request::getFormat() const
{
    return format;
}

void Request::setFormat(const QString &value)
{
    format = value;
}

int Request::getQuality() const
{
    return quality;
}

void Request::setQuality(int value)
{
    quality = value;
}

int Request::getTileMax() const
{
    return tileMax;
}

void Request::setTileMax(int value)
{
    tileMax = value;
}

int Request::getTileHeight() const
{
    return tileHeight;
}

void Request::setTileHeight(int value)
{
    tileHeight = value;
}

void Request::print()
{
    LOG(DEBUG) << "Request : print()";
    LOG(DEBUG) << "  productNo:" << productNo;
    LOG(DEBUG) << "  url:" << url;
    LOG(DEBUG) << "  dir" << dir;
    LOG(DEBUG) << "  prefix:" << prefix;
    LOG(DEBUG) << "  format:" << format;
    LOG(DEBUG) << "  quality:" << quality;
    LOG(DEBUG) << "  tileMax:" << tileMax;
    LOG(DEBUG) << "  tileHeight:" << tileHeight;
}
