#include "common.hh"

void logging(QtMsgType type, const char *msg)
{
    struct tm *t;
    time_t ct;

    time(&ct);
    t = localtime(&ct);

    switch (type) {
        case QtDebugMsg:
            fprintf(stdout, "%d-%02d-%02d %02d:%02d:%02d [DEBUG] %s\n", (t->tm_year) + 1900, (t->tm_mon) + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, msg);
            break;
        case QtWarningMsg:
            fprintf(stdout, "%d-%02d-%02d %02d:%02d:%02d [WARN ] %s\n", (t->tm_year) + 1900, (t->tm_mon) + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, msg);
            break;
        case QtCriticalMsg:
            fprintf(stdout, "%d-%02d-%02d %02d:%02d:%02d [CRITI] %s\n", (t->tm_year) + 1900, (t->tm_mon) + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, msg);
            break;
        case QtFatalMsg:
            fprintf(stdout, "%d-%02d-%02d %02d:%02d:%02d [FATAL] %s\n", (t->tm_year) + 1900, (t->tm_mon) + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, msg);
            abort();
    }
}
