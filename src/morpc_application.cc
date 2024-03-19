#include "morpc_application.h"

#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

static void Usage(const char *argv)
{
    cout << "fomat: " << argv << " -i <configfile>" << endl;
}

namespace morpc
{
    MoRpcConfig MorpcApplication::config_;

    void MorpcApplication::Init(int argc, char *argv[])
    {
        if (argc < 2)
        {
            Usage(argv[0]);
            exit(EXIT_FAILURE);
        }

        int c;
        string config_file = "";
        while ((c = getopt(argc, argv, "i:")) != -1)
        {
            switch (c)
            {
            case 'i':
                config_file = optarg;
                break;
            case '?':
            case ':':
                Usage(argv[0]);
                exit(EXIT_FAILURE);
            default:
                break;
            }
        }

        // 开始加载配置文件
        config_.LoadConfigFile(config_file.c_str());

        /// 测试
        std::cout << "rpcserver_ip:" << config_.Select("rpcserver_ip") << std::endl;
        std::cout << "rpcserver_port:" << config_.Select("rpcserver_port") << std::endl;
        std::cout << "zookeeper_ip:" << config_.Select("zookeeper_ip") << std::endl;
        std::cout << "zookeeper_port:" << config_.Select("zookeeper_port") << std::endl;
    }
}