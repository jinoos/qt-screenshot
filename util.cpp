#include "util.hh"
#include "procps-3.2.8/proc/readproc.h"

Util::Util()
{
}

const char *Util::cStr(const QString &s)
{
    return s.toStdString().c_str();
}

const char *Util::boolStr(bool b)
{
    if(b)
        return "true";
    else
        return "false";
}

qint64 Util::getMemUsage()
{
    struct proc_t usage;
    look_up_our_self(&usage);
    return (qint64) usage.resident;
}
