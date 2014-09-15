#ifndef REQUEST_HH
#define REQUEST_HH

#include <QString>
#include "common.hh"

#define DEFAULT_FORMAT          "jpg"
#define DEFAULT_QUALITY         85
#define DEFAULT_TILE_MAX        65536
#define DEFAULT_TILE_HEIGHT     1000

class Request
{
private:
    qint64 productNo;
    QString url;
    QString dir;
    QString prefix;
    QString format;
    int quality;
    int tileMax;
    int tileHeight;

    static bool checkJsonMandatory(json_t *json, const char *key, json_type type);
    static bool checkJsonType(json_t *json, const char *key, json_type type);
    static const char *getJsonString(json_t *json, const char *key, const char *def);
    static qint64 getJsonLong(json_t *json, const char *key, qint64 def);
    static int getJsonInt(json_t *json, const char *key, int def);

public:
    Request();
    Request(qint64 p, QString &url, QString &dir, QString &prefix);
    Request(qint64 p, const char *url, const char *dir, const char *prefix);

    static Request* fromJson(const char *json);

    qint64 getProductNo() const;
    void setProductNo(qint64 value);
    const QString& getUrl() const;
    void setUrl(const QString &value);
    const QString& getDir() const;
    void setDir(const QString &value);
    const QString& getPrefix() const;
    void setPrefix(const QString &value);
    const QString& getFormat() const;
    void setFormat(const QString &value);
    int getQuality() const;
    void setQuality(int value);
    int getTileMax() const;
    void setTileMax(int value);
    int getTileHeight() const;
    void setTileHeight(int value);
    void print();
};

#endif // REQUEST_HH
