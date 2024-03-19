#include "morpc_util.h"

#include <algorithm>

namespace morpc
{
    void RemoveSpaces(std::string &str)
    {
        str.erase(std::remove_if(str.begin(), str.end(), [](char c)
                                 { return std::isspace(c); }),
                  str.end());
    }
}
