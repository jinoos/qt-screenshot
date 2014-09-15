#include "result.hh"


Request* Result::getRequest() const
{
    return request;
}

void Result::setRequest(Request *value)
{
    request = value;
}

int Result::getScreenWidth() const
{
    return screenWidth;
}

void Result::setScreenWidth(int value)
{
    screenWidth = value;
}

int Result::getScreenHeight() const
{
    return screenHeight;
}

void Result::setScreenHeight(int value)
{
    screenHeight = value;
}

int Result::getImageCount() const
{
    return imageCount;
}

void Result::setImageCount(int value)
{
    imageCount = value;
}

void Result::print()
{
    LOG(DEBUG) << "Result : print()";
    LOG(DEBUG) << "  success:" << success;
    LOG(DEBUG) << "  loaded:" << loaded;
    LOG(DEBUG) << "  generated:" << generated;
    LOG(DEBUG) << "  screenWidth:" << screenWidth;
    LOG(DEBUG) << "  screenHeight:" << screenHeight;
    LOG(DEBUG) << "  imageGeneratedCount:" << imageGeneratedCount;
    LOG(DEBUG) << "  imageCount:" << imageCount;
    LOG(DEBUG) << "  loadElapsed:" << loadElapsed;
    LOG(DEBUG) << "  totalElapsed:" << totalElapsed;
    LOG(DEBUG) << "  files:" << files.size();
    for(int i = 0; i < files.size(); i++)
    {
        LOG(DEBUG) << "    " << files.at(i);
    }
}

int Result::getTotalElapsed() const
{
    return totalElapsed;
}

void Result::setTotalElapsed(int value)
{
    totalElapsed = value;
}

void Result::start()
{
    stopWatch.start();
}

void Result::loadingEnd()
{
    loadElapsed = stopWatch.elapsed();
}

void Result::allDone()
{
    totalElapsed = stopWatch.elapsed();
}


QString Result::getFailReason() const
{
    return failReason;
}

void Result::setFailReason(const QString &value)
{
    failReason = value;
}

void Result::appendFailReason(const QString &value)
{
    failReason.append(value);
}

void Result::setFailReason(const char *value)
{
    failReason = value;
}

void Result::appendFailReason(const char *value)
{
    failReason.append(value);
}


bool Result::getSuccess() const
{
    return success;
}

void Result::setSuccess(bool value)
{
    success = value;
}

bool Result::getLoaded() const
{
    return loaded;
}

void Result::setLoaded(bool value)
{
    loaded = value;
}

bool Result::getGenerated() const
{
    return generated;
}

void Result::setGenerated(bool value)
{
    generated = value;
}
Result::Result()
    : success(false),
      loaded(false),
      generated(false),
      request(NULL),
      failReason("")
{
}

Result::Result(Request *req)
    : success(false),
      loaded(false),
      generated(false),
      request(req),
      failReason("")
{
}

Result::~Result()
{
    if(request != NULL)
        delete request;
}

json_t *Result::getJson()
{
    json_t *json = json_object();

//    if(success)
//    {

//    }else
//    {
        json_object_set(json, "success", json_pack("b", success));
        json_object_set(json, "failReason", json_pack("s", Util::cStr(failReason)));
//    }

//    json = json_pack("{"
//                     "s:i," // productNo
//                     "s:b," // success
//                     "s:b," // loaded
//                     "s:b," // generated
//                     "s:i," // screenWidth
//                     "s:i," // screenHeight
//                     "s:i," // imageGeneratedCount
//                     "s:i," // imageCount
//                     "s:i," // loadElapsed
//                     "s:i," // totalElapsed
//                     "s:s"  // failReason
//                     "}",
//                     "productNo", request->getProductNo(),
//                     "success", success,
//                     "loaded", loaded,
//                     "generated", generated,
//                     "screenWidth", (qint64)screenWidth,
//                     "screenHeight", (qint64)screenHeight,
//                     "imageGeneratedCount", (qint64)screenHeight,
//                     "imageGeneratedCount", (qint64)imageGeneratedCount,
//                     "imageCount", (qint64)imageCount,
//                     "loadElapsed", (qint64)loadElapsed,
//                     "totalElapsed", (qint64)totalElapsed,
//                     "failReason", Util::cStr(failReason)
//                     );

    char *json_str = json_dumps(json, JSON_ENCODE_ANY);
    if(json_str != NULL)
    {
        LOG(DEBUG) << "JSON String " << json_str;
        free(json_str);
    }

    return json;
}

