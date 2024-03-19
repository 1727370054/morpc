#include "morpc_config.h"
#include "morpc_util.h"

#include <iostream>
#include <fstream>

namespace morpc
{
    void MoRpcConfig::LoadConfigFile(const char *config_file)
    {
        std::ifstream ifs(config_file, std::ios::in);
        if (!ifs.is_open())
        {
            std::cerr << "open " << config_file << " failed!" << std::endl;
            exit(EXIT_FAILURE);
        }

        std::string line = "";
        while (std::getline(ifs, line))
        {
            // 去空格
            RemoveSpaces(line);
            // 去注释
            if (line[0] == '#' || line.empty())
                continue;

            auto pos = line.find("=");
            if (pos != std::string::npos)
            {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                config_map_[key] = value;
            }
        }

        ifs.close();
    }

    std::string MoRpcConfig::Select(const std::string &key)
    {
        auto iter = config_map_.find(key);
        if (iter == config_map_.end())
            return "";
        return iter->second;
    }
}
