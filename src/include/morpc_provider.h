#ifndef __MORPC_PROVIDER_H__
#define __MORPC_PROVIDER_H__

/*
 * @brief 发布rpc服务的网络对象类
 */

#include "google/protobuf/service.h"

namespace morpc
{
    class MorpcProvider
    {
    public:
        ~MorpcProvider() {}
        MorpcProvider() {}

        /// @brief 发布rpc方法
        /// @param service rpc服务提供类对象指针
        void NotifyService(google::protobuf::Service *service);

        /// @brief 启动rpc服务节点，启动后阻塞等待远程rpc调用请求
        void Run();
    };
}

#endif