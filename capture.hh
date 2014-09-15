#ifndef CAPTURE_HH
#define CAPTURE_HH

#include <QApplication>
#include <QObject>
#include <QObject>
#include <QDebug>
#include <QWebView>
#include <QTimer>
#include <QTimerEvent>
#include "common.hh"


class Result;
class Redis;
class WebViewRemoveQue;

class Capture : public QObject
{
Q_OBJECT

private:
    QApplication *app;
    Redis       *redis;
    WebViewRemoveQue *rmQue;
    QWebView    *view;
    Request     *request;
    Result      *result;
    int         maxMemUsage;

    int         waitInterval;
    int         loadTimeout;

    int         sleepTimer;
    int         loadTimer;

    void timerEvent(QTimerEvent *event);
    void load();
    void clear();

public:
    Capture(QApplication *app, Redis *redis, WebViewRemoveQue *rmQue, qint64 maxMemUsage, long loadTimeout);
    void start();
    //capture();

signals:
    void captureStarted(Request &request);
    void loadStarted();
    void loadFinished(bool ok, Result &response);
    void generateStarted(Result &response);
    void generateFinished(Result &result);

public slots:
    void getRequest();
    void _loadStarted();
    void _loadProgress(int p);
    void _loadFinished(bool ok);
};

#endif // CAPTURE_HH
