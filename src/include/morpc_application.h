#ifndef __MORPC_APPLICATION_H__
#define __MORPC_APPLICATION_H__

/*
 * @brief morpc框架的基础类, 负责框架的初始化操作
 */

#include "morpc_config.h"

namespace morpc
{
    class MoRpcApplication
    {
    public:
        ~MoRpcApplication() {}

        static MoRpcApplication &GetInstance()
        {
            static MoRpcApplication morpc_app;
            return morpc_app;
        }

        /// @brief 接收命令行参数，进行初始化操作
        static void Init(int argc, char *argv[]);

        /// @brief 返回 MoRpcConfig 对象
        MoRpcConfig &GetConfig();

    private:
        MoRpcApplication() {}
        MoRpcApplication(const MoRpcApplication &) = delete;
        MoRpcApplication &operator=(const MoRpcApplication &) = delete;

    private:
        static MoRpcConfig config_;
    };
}

#endif