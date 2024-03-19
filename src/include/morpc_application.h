#ifndef __MORPC_APPLICATION_H__
#define __MORPC_APPLICATION_H__

/*
 * @brief morpc框架的基础类, 负责框架的初始化操作
 */

#include "morpc_config.h"

namespace morpc
{
    class MorpcApplication
    {
    public:
        ~MorpcApplication() {}

        static MorpcApplication &GetInstance()
        {
            static MorpcApplication morpc_app;
            return morpc_app;
        }

        /// @brief 接收命令行参数，进行初始化操作
        static void Init(int argc, char *argv[]);

    private:
        MorpcApplication() {}
        MorpcApplication(const MorpcApplication &) = delete;
        MorpcApplication &operator=(const MorpcApplication &) = delete;

    private:
        static MoRpcConfig config_;
    };
}

#endif