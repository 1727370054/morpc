#ifndef __MORPC_PROVIDER_H__
#define __MORPC_PROVIDER_H__

/*
 * @brief 发布rpc服务的网络对象类, 在框架内部Provider和Consumer通过protobuf进行数据交互
 * 格式: 服务名称 方法名称 参数数据大小(字节)
 */

#include <google/protobuf/service.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <string>
#include <unordered_map>

namespace morpc
{
    struct ServiceInfo
    {
        /// @brief 保存服务对象
        google::protobuf::Service *m_service = nullptr;
        /// @brief key: 方法名称, value: 方法描述
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor *> m_method_map;
    };

    class MoRpcProvider
    {
    public:
        ~MoRpcProvider() {}
        MoRpcProvider() {}

        /// @brief 发布rpc方法
        /// @param service rpc服务提供类对象指针
        void NotifyService(google::protobuf::Service *service);

        /// @brief 启动rpc服务节点，启动后阻塞等待远程rpc调用请求
        void Run();

        /// @brief 设置muduo库线程数量
        void set_thread_num(int thread_num) { thread_num_ = thread_num; }

    private:
        /// @brief socket连接成功回调函数
        void OnConnection(const muduo::net::TcpConnectionPtr &conn_ptr);
        /// @brief 已经建立好连接用户读写事件回调, 用于处理rpc调用请求
        void OnMessage(const muduo::net::TcpConnectionPtr &conn_ptr,
                       muduo::net::Buffer *buffer,
                       muduo::Timestamp timestamp);

        /// @brief Closure的回调函数, 用于序列化rpc响应和网络发送
        void SendRpcResponse(const muduo::net::TcpConnectionPtr &conn_ptr,
                             google::protobuf::Message *response);

    private:
        muduo::net::EventLoop event_loop_;
        /// @brief key: 服务名称, value: 服务的所有信息(方法以及对象)
        std::unordered_map<std::string, ServiceInfo> service_info_map_;
        int thread_num_ = 4;
    };
}

#endif