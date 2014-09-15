#include "webviewremover.hh"

void WebViewRemover::timerEvent(QTimerEvent *event)
{
    LOG(DEBUG) << "timerEvent : timer ID:" << event->timerId();
    killTimer(event->timerId());
    remove();
}

WebViewRemover::WebViewRemover(WebViewRemoveQue *viewQue, int sleepMiliSeconds)
    : viewQue(viewQue),
      sleepMiliSeconds(sleepMiliSeconds)
{

}

void WebViewRemover::start()
{
    remove();
}

void WebViewRemover::remove()
{
    LOG(DEBUG) << "remove";

    QWebView *view = NULL;

    while((view = viewQue->deque()) != NULL)
    {
        LOG(DEBUG) << "remove : removed QWebView instance.";
        delete view;
        view = NULL;
    }
    startTimer(sleepMiliSeconds);
}
