#include "json.hh"

json::json()
{
}

bool json::validateRequest(json_t *json)
{
    if(json == NULL)
        return false;

    return true;
}
