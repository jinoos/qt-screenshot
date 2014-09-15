#ifndef WEBVIEWREMOVEQUE_HH
#define WEBVIEWREMOVEQUE_HH

#include <QWebView>
#include <QList>
#include <QTime>
#include <QMutex>

class WebViewRemoveQueShell;

class WebViewRemoveQue
{
    QList<WebViewRemoveQueShell*> list;
    int delay;
    QMutex lock;

public:
    WebViewRemoveQue(int delay);
    ~WebViewRemoveQue();

    void enque(QWebView *view);
    QWebView* deque();

    int size();
};

class WebViewRemoveQueShell
{
public:
    QWebView *view;
    int     ttl;

    WebViewRemoveQueShell(QWebView *view, int delay)
        : view(view)
    {
        ttl = QTime::currentTime().second()+delay;
    }
};

#endif // WEBVIEWREMOVEQUE_HH
