#ifndef JSON_HH
#define JSON_HH

#include "common.hh"

class json
{
public:
    json();

    static bool validateRequest(json_t *json);
};

#endif // JSON_HH
