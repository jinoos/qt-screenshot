#include "capture.hh"
#include <stdio.h>

void Capture::getRequest()
{
    qint64 musage = 0;
    musage = Util::getMemUsage();
    LOG(DEBUG) << "Current memory usage " << (musage/(1024*1024)) << "MB";
//    if(musage > maxMemUsage)
//    {
//        LOG(FATAL) << "Memory usage is over limitation. (" << musage << ":" << maxMemUsage << ")";
//    }
    if(!redis->connected())
        redis->connect();

    clear();

    request = redis->getRequest();

    if(request == NULL)
    {
        LOG(DEBUG) << "getRequest() : no request.";
        sleepTimer = startTimer(waitInterval);
        return;
    }

    result = new Result(request);
    load();
}

void Capture::timerEvent(QTimerEvent *event)
{
    killTimer(event->timerId());
    if(event->timerId() == sleepTimer)
    {
        getRequest();
    }else if(event->timerId() == loadTimer)
    {
        if(view != NULL)
            view->stop();

        disconnect(this, SLOT(_loadStarted()));
        disconnect(this, SLOT(_loadProgress(int)));
        disconnect(this, SLOT(_loadFinished(bool)));

        LOG(DEBUG) << "timeout to load the page " << request->getUrl();
        result->setSuccess(false);
        result->setFailReason("Capture : over timeout to load the page, url ");
        result->appendFailReason(request->getUrl());

        // Need to send fail result.
        // here!!
        result->getJson();

        // go back to first step.
        getRequest();
    }
}

void Capture::load()
{
    if(result == NULL)
    {
        startTimer(waitInterval);
        return;
    }

    result->setSuccess(false);
    result->setLoaded(false);
    result->setGenerated(false);

    view = new QWebView();
    connect(view, SIGNAL(loadStarted()), this, SLOT(_loadStarted()));
    connect(view, SIGNAL(loadProgress(int)), this, SLOT(_loadProgress(int)));
    connect(view, SIGNAL(loadFinished(bool)), this, SLOT(_loadFinished(bool)));
    view->settings()->setMaximumPagesInCache(0);
    view->settings()->setObjectCacheCapacities(0, 0, 0);
    view->settings()->setOfflineStorageDefaultQuota(0);
    loadTimer = startTimer(waitInterval);
    result->start();
    view->load(request->getUrl());
}

void Capture::clear()
{
    if(view != NULL)
    {
        rmQue->enque(view);
        //delete view;
        view = NULL;
    }

    if(result == NULL && request != NULL)
    {
        delete request;
        request = NULL;
    }else if(result != NULL)
    {
        delete result;
        result = NULL;
    }

    sleepTimer = 0;
    loadTimer = 0;
}

Capture::Capture(QApplication *app, Redis *redis, WebViewRemoveQue *rmQue, qint64 maxMemUsage, long loadTimeout)
    : app(app),
      redis(redis),
      rmQue(rmQue),
      view(NULL),
      request(NULL),
      result(NULL),
      maxMemUsage(maxMemUsage),
      loadTimeout(loadTimeout)
{
    this->redis = redis;
    waitInterval = CAPTURE_INTERVAL;
}

void Capture::start()
{
    getRequest();
}

void Capture::_loadStarted()
{
    emit loadStarted();
}

void Capture::_loadProgress(int)
{
}


void Capture::_loadFinished(bool ok)
{
    result->setLoaded(true);

    // do something here



    // go back to first
    getRequest();
}
