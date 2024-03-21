#ifndef __MORPC_CONFIG_H__
#define __MORPC_CONFIG_H__

/*
 * @brief 框架读取配置文件类
 * rpcserver_ip rpcserver_port zookeeper_ip zookeeper_port
 */

#include <unordered_map>
#include <string>

namespace morpc
{
    class MoRpcConfig
    {
    public:
        /// @brief 负责加载配置文件
        /// @param config_file 配置文件路径
        void LoadConfigFile(const char *config_file);

        /// @brief 查询配置项信息
        /// @param key 需要查询的配置项key值
        /// @return 存在返回配置项key对应的value，不存在返回空串
        std::string Select(const std::string &key);

    private:
        std::unordered_map<std::string, std::string> config_map_;
    };
}

#endif