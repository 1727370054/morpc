#include "morpc_provider.h"
#include "morpc_application.h"
#include "morpc_header.pb.h"

#include <functional>
#include <google/protobuf/descriptor.h>

namespace morpc
{

#define HEADER_SIZE sizeof(uint32_t)

    void MorpcProvider::NotifyService(google::protobuf::Service *service)
    {
        // 获取服务对象的描述信息
        const google::protobuf::ServiceDescriptor *service_desc = service->GetDescriptor();
        // 获取服务名称
        std::string service_name = service_desc->name();
        // 获取服务对象的方法数量
        int method_count = service_desc->method_count();

        ServiceInfo service_info;
        for (int i = 0; i < method_count; i++)
        {
            // 根据下标获取服务对象对应的方法描述
            const google::protobuf::MethodDescriptor *method_desc = service_desc->method(i);
            std::string method_name = method_desc->name();
            service_info.m_method_map.insert({method_name, method_desc});
        }
        service_info.m_service = service;
        service_info_map_.insert({service_name, service_info});
    }

    void MorpcProvider::Run()
    {
        std::string ip = MorpcApplication::GetInstance().GetConfig().Select("rpcserver_ip");
        uint16_t port = atoi(MorpcApplication::GetInstance().GetConfig().Select("rpcserver_port").c_str());
        muduo::net::InetAddress address(ip, port);

        muduo::net::TcpServer server(&event_loop_, address, "RpcProvider");
        // 绑定连接回调和消息读写回调
        server.setConnectionCallback(std::bind(&MorpcProvider::OnConnection, this, std::placeholders::_1));
        server.setMessageCallback(std::bind(&MorpcProvider::OnMessage, this, std::placeholders::_1,
                                            std::placeholders::_2, std::placeholders::_3));

        // 设置线程数量
        server.setThreadNum(thread_num_);

        // 启动网络服务
        server.start();

        std::cout << "RpcProvider start service at ip: " << ip << " port: " << port << std::endl;
        std::cout << "thread num: " << thread_num_ << std::endl;

        event_loop_.loop();
    }

    void MorpcProvider::OnConnection(const muduo::net::TcpConnectionPtr &conn_ptr)
    {
        if (!conn_ptr->connected())
        {
            // 连接已经断开
            conn_ptr->shutdown(); // 关闭文件描述符
        }
    }

    /*
     * 协议格式: 前4个字节头部大小, 后面跟着头部, 头部数据后, 就是参数数据
     * 头部协议:
     *         message MoRpcHeader
     *         {
     *             bytes service_name = 1;
     *             bytes method_name = 2;
     *             uint32 args_size = 3;
     *         }
     */
    void MorpcProvider::OnMessage(const muduo::net::TcpConnectionPtr &conn_ptr,
                                  muduo::net::Buffer *buffer,
                                  muduo::Timestamp timestamp)
    {
        // 网络接收的rpc请求字符流
        std::string recv_buf = buffer->retrieveAllAsString();

        // 读头部大小
        uint32_t header_size = 0;
        recv_buf.copy((char *)&header_size, HEADER_SIZE, 0);

        // 根据header_size读取头部信息
        std::string rpc_header_str = recv_buf.substr(HEADER_SIZE, header_size);
        // 反序列化
        morpc::MoRpcHeader morpc_header;
        if (!morpc_header.ParseFromString(rpc_header_str))
        {
            std::cout << "parse header error!" << std::endl;
            return;
        }

        std::string service_name = morpc_header.service_name();
        std::string method_name = morpc_header.method_name();
        uint32_t args_size = morpc_header.args_size();

        // 获取rpc方法参数数据
        std::string rpc_args_str = recv_buf.substr(HEADER_SIZE + header_size, args_size);

        // 打印调试信息
        std::cout << "======================================================" << std::endl;
        std::cout << "header_size: " << header_size << std::endl;
        std::cout << "service_name: " << service_name << std::endl;
        std::cout << "method_name: " << method_name << std::endl;
        std::cout << "args_size: " << args_size << std::endl;
        std::cout << "args: " << rpc_args_str << std::endl;
        std::cout << "======================================================" << std::endl;

        // 获取service对象和method对象
        auto iter = service_info_map_.find(service_name);
        if (iter == service_info_map_.end())
        {
            std::cout << "service: " << service_name << " is not exist" << std::endl;
            return;
        }

        auto m = iter->second.m_method_map.find(method_name);
        if (m == iter->second.m_method_map.end())
        {
            std::cout << service_name << ":" << method_name << " is not exist" << std::endl;
            return;
        }
        google::protobuf::Service *service = iter->second.m_service;
        const google::protobuf::MethodDescriptor *method_desc = m->second;

        // 生成rpc方法调用的request和response参数
        google::protobuf::Message *request = service->GetRequestPrototype(method_desc).New();
        google::protobuf::Message *response = service->GetResponsePrototype(method_desc).New();
        if (!request->ParseFromString(rpc_args_str))
        {
            std::cout << "parse request error, content: " << rpc_args_str << std::endl;
            return;
        }

        // 给CallMethod绑定一个Closure的回调函数
        google::protobuf::Closure *done =
            google::protobuf::NewCallback<MorpcProvider, const muduo::net::TcpConnectionPtr &, google::protobuf::Message *>(this, &MorpcProvider::SendRpcResponse, conn_ptr, response);

        // 根据rpc请求调用rpc节点发布的方法
        service->CallMethod(method_desc, nullptr, request, response, done);
    }

    void MorpcProvider::SendRpcResponse(const muduo::net::TcpConnectionPtr &conn_ptr,
                                        google::protobuf::Message *response)
    {
        std::string response_str;
        if (response->SerializeToString(&response_str))
            conn_ptr->send(response_str);
        else
            std::cout << "serialize response error!" << std::endl;

        conn_ptr->shutdown(); // 短链接, 由rpc Provider方主动断开连接
    }
}