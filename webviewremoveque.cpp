#include "webviewremoveque.hh"

WebViewRemoveQue::WebViewRemoveQue(int delay)
    : delay(delay),
      list(),
      lock()
{
}

WebViewRemoveQue::~WebViewRemoveQue()
{
    WebViewRemoveQueShell *shell;
    while((shell = list.takeFirst()) != NULL)
        delete shell;
}

void WebViewRemoveQue::enque(QWebView *view)
{
    lock.lock();
    WebViewRemoveQueShell *shell = new WebViewRemoveQueShell(view, delay);
    list.append(shell);
    lock.unlock();
}

QWebView *WebViewRemoveQue::deque()
{
    lock.lock();
    if(list.isEmpty())
    {
        lock.unlock();
        return NULL;
    }


    if(list[0]->ttl < QTime::currentTime().second())
    {
        WebViewRemoveQueShell *shell = list.takeFirst();
        QWebView *view = shell->view;
        delete shell;
        lock.unlock();
        return view;
    }

    lock.unlock();
    return NULL;
}

int WebViewRemoveQue::size()
{
    return list.size();
}
