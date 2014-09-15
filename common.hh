#ifndef COMMON_HH
#define COMMON_HH

#include <QDebug>

#include "jansson.h"
#include "redis.hh"
#include "request.hh"
#include "result.hh"
#include "capture.hh"
#include "webviewremoveque.hh"
#include "webviewremover.hh"
#include "easyloggingpp/src/easylogging++.h"
#include "util.hh"
#include "version.h"

#ifdef LOG_FILELINE
#define LOGGING_FORMAT  \
    "* GLOBAL:\n" \
    "   FORMAT = %datetime{%Y-%M-%d %H:%m:%s} [%level] [%file(%line)] %msg\n"
#else // LOG_FILELINE
#define LOGGING_FORMAT  \
    "* GLOBAL:\n" \
    "   FORMAT = %datetime{%Y-%M-%d %H:%m:%s} [%level] %msg\n"
#endif // LOG_FILELINE

#define CAPTURE_INTERVAL            1000

#define REQ_JSON_PRODUCT_NO         "product_no"       // mandatory
#define REQ_JSON_URL                "url"           // mandatory
#define REQ_JSON_DIR                "dir"           // mandatory
#define REQ_JSON_PREFIX             "prefix"        // mandatory
#define REQ_JSON_FORMAT             "format"        // default jpg
#define REQ_JSON_QUALITY            "quality"       // default 85
#define REQ_JSON_TILE_MAX           "tile_max"      // default unlimit
#define REQ_JSON_TILE_HEIGHT        "tile_height"   // default 1000


#define RES_JSON_PRODUCT_NO         "product_no"       // mandatory
#define RES_JSON_URL                "url"           // mandatory
#define RES_JSON_DIR                "dir"           // mandatory
#define RES_JSON_PREFIX             "prefix"        // mandatory
#define RES_JSON_FORMAT             "format"        // default jpg
#define RES_JSON_QUALITY            "quality"       // default 85
#define RES_JSON_TILE_MAX           "tile_max"      // default unlimit
#define RES_JSON_TILE_HEIGHT        "tile_height"   // default 1000

#define RES_JSON_SUCCESS            "success"       // mandatory
#define RES_JSON_SCREEN_WIDTH       "screen_width"  // mandatory
#define RES_JSON_SCREEN_HEIGHT      "screen_height" // mandatory
#define RES_JSON_IMAGE_GENERATE_COUNT "image_generate_count"    // mandatory
#define RES_JSON_IMAGE_COUNT        "image_count"   // mandatory
#define RES_JSON_LOAD_ELASPED       "load_elapsed"  // optional
#define RES_JSON_GENERATE_ELAPSED   "load_elapsed"  // optional
#define RES_JSON_FAIL_MESSAGE       "fail_message"  // optional


void logging(QtMsgType type, const char *msg);

/*
QDebug qDebugns()
{
    return qDebug().nospace();
}

QDebug qWarningns()
{
    return qWarning().nospace();
}

QDebug qCriticalns()
{
    return qCritical().nospace();
}
*/
#endif // COMMON_HH
