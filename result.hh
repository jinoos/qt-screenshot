#ifndef RESULT_HH
#define RESULT_HH

#include <QList>
#include <QTime>
#include "request.hh"
#include "common.hh"

class Request;


class Result
{
    bool success;
    bool loaded;
    bool generated;

    Request *request;

    int screenWidth;
    int screenHeight;
    int imageGeneratedCount;
    int imageCount;
    int loadElapsed;
    int totalElapsed;
    QTime stopWatch;
    QList<QString> files;
    QString failReason;

public:
    Result();
    Result(Request *req);
    ~Result();

    json_t* getJson();

    qint64 getLoadElapsed();
    qint64 getGenerateElapsed();
    void addFile(QString &file);
    int getImageGeneratedCount();
    Request* getRequest() const;
    void setRequest(Request *value);
    int getScreenWidth() const;
    void setScreenWidth(int value);
    int getScreenHeight() const;
    void setScreenHeight(int value);
    int getImageCount() const;
    void setImageCount(int value);
    int getTotalElapsed() const;
    void setTotalElapsed(int value);
    void start();
    void loadingEnd();
    void allDone();

    void print();

    QString getFailReason() const;
    void setFailReason(const QString &value);
    void appendFailReason(const QString &value);
    void setFailReason(const char *value);
    void appendFailReason(const char *value);
    bool getSuccess() const;
    void setSuccess(bool value);
    bool getLoaded() const;
    void setLoaded(bool value);
    bool getGenerated() const;
    void setGenerated(bool value);
};

#endif // RESULT_HH
