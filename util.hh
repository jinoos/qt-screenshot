#ifndef UTIL_HH
#define UTIL_HH

#include <QString>

class Util
{
public:
    Util();

    static const char* cStr(const QString &s);
    static const char* boolStr(bool b);
    static qint64 getMemUsage();
};

#endif // UTIL_HH
