#ifndef __MORPC_CHANNEL_H__
#define __MORPC_CHANNEL_H__

#include <google/protobuf/service.h>

namespace morpc
{
    class MoRpcChannel : public google::protobuf::RpcChannel
    {
    public:
        /// @brief 所有通过*_Stub类代理对象调用的rpc方法, 都回调到这里, 统一做rpc方法调用的参数序列化和网络发送
        /// @param method 调用对应方法的描述
        /// @param controller RPC调用状态和控制的接口
        /// @param request RPC调用的参数
        /// @param response RPC调用需要的响应
        /// @param done 响应的回调函数
        virtual void CallMethod(const google::protobuf::MethodDescriptor *method,
                                google::protobuf::RpcController *controller,
                                const google::protobuf::Message *request,
                                google::protobuf::Message *response,
                                google::protobuf::Closure *done) override;

        /// @brief 设置rpc调用超时时间, 单位毫秒, 超时返回, 默认3 秒
        void set_timeout(int timeout_sec) { timeout_sec = timeout_sec_; }

        /// @brief 用于判断是否超时返回, 还是执行失败
        /// @return true 表示超时返回, false表示rpc调用执行失败
        bool is_timeout() { return is_timeout_; }

    private:
        /// @brief 进行select I/O多路复用, 监听读事件
        /// @return select的返回值
        int Select(int &fd);

    private:
        /// @brief rpc调用超时时间(秒)
        int timeout_sec_ = 3;
        bool is_timeout_ = false;
    };
}

#endif