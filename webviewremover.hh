#ifndef WEBVIEWREMOVER_HH
#define WEBVIEWREMOVER_HH

#include <QDebug>
#include <QTimerEvent>
#include "common.hh"

class WebViewRemover : public QObject
{
Q_OBJECT
    WebViewRemoveQue *viewQue;
    int sleepMiliSeconds;

    void timerEvent(QTimerEvent *event);
    void remove();

public:
    WebViewRemover(WebViewRemoveQue *viewQue, int sleepMiliSeconds);
    void start();
};

#endif // WEBVIEWREMOVER_HH
