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
    MoRpcConfig MoRpcApplication::config_;

    void MoRpcApplication::Init(int argc, char *argv[])
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
    }

    MoRpcConfig &MoRpcApplication::GetConfig()
    {
        return config_;
    }
}
