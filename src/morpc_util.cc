#include "morpc_util.h"

#include <algorithm>
#include <time.h>

namespace morpc
{
    void RemoveSpaces(std::string &str)
    {
        str.erase(std::remove_if(str.begin(), str.end(), [](char c)
                                 { return std::isspace(c); }),
                  str.end());
    }

    std::string GetCurTime(int timestamp, std::string format)
    {
        char buf[128] = {0};
        time_t tm = timestamp;
        if (tm <= 0)
            tm = time(0);
        strftime(buf, sizeof(buf), format.c_str(), localtime(&tm));
        return buf;
    }
}
