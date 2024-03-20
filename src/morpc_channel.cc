#include "morpc_channel.h"
#include "morpc_header.pb.h"
#include "morpc_application.h"

#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <unistd.h>
#include <errno.h>
#include <string>
#include <memory>
#include <cstring>

/*
 * 协议格式: header_size + service_name + method_name + args_size + args
 *          header_size = (service_name + method_name + args_size) 序列化后的长度
 */

namespace morpc
{
    auto fdDeleter = [](int *fd)
    {
        if (fd && *fd != -1)
        {
            ::close(*fd);
            std::cout << "File descriptor " << *fd << " closed." << std::endl;
        }
        delete fd;
    };

    void MoRpcChannel::CallMethod(const google::protobuf::MethodDescriptor *method,
                                  google::protobuf::RpcController *controller,
                                  const google::protobuf::Message *request,
                                  google::protobuf::Message *response,
                                  google::protobuf::Closure *done)
    {
        const google::protobuf::ServiceDescriptor *service_desc = method->service();
        std::string service_name = service_desc->name();
        std::string method_name = method->name();

        std::string rpc_args_str = request->SerializeAsString();
        // 序列化后的数据大小
        size_t rpc_args_size = request->ByteSizeLong();

        // rpc请求头
        morpc::MoRpcHeader header;
        header.set_service_name(service_name);
        header.set_method_name(method_name);
        header.set_args_size(rpc_args_size);

        std::string rpc_header_str = header.SerializeAsString();
        size_t rpc_header_size = header.ByteSizeLong();

        // 组装rpc请求字符串序列
        std::string send_rpc_str((char *)&rpc_header_size, 4);
        send_rpc_str += rpc_header_str;
        send_rpc_str += rpc_args_str;

        // 打印调试信息
        std::cout << "======================================================" << std::endl;
        std::cout << "header_size: " << rpc_header_size << std::endl;
        std::cout << "service_name: " << service_name << std::endl;
        std::cout << "method_name: " << method_name << std::endl;
        std::cout << "args_size: " << rpc_args_size << std::endl;
        std::cout << "args: " << rpc_args_str << std::endl;
        std::cout << "======================================================" << std::endl;

        std::unique_ptr<int, decltype(fdDeleter)> fd(new int(-1), fdDeleter);
        *fd = socket(AF_INET, SOCK_STREAM, 0);
        if (-1 == *fd)
        {
            char errtxt[512] = {0};
            sprintf(errtxt, "create socket error! errno:%d", errno);
            // controller->SetFailed(errtxt);
            return;
        }

        std::string ip = MorpcApplication::GetInstance().GetConfig().Select("rpcserver_ip");
        uint16_t port = atoi(MorpcApplication::GetInstance().GetConfig().Select("rpcserver_port").c_str());

        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

        // 连接rpc服务节点
        if (-1 == connect(*fd, (struct sockaddr *)&server_addr, sizeof(server_addr)))
        {
            char errtxt[512] = {0};
            sprintf(errtxt, "connect error! errno:%d", errno);
            // controller->SetFailed(errtxt);
            return;
        }

        // 发送rpc请求
        if (::send(*fd, send_rpc_str.c_str(), send_rpc_str.size(), 0) == -1)
        {
            std::cout << "send rpc request failed! errno: " << errno << std::endl;
            return;
        }

        // 接收rpc响应
        int ret = Select(*fd);
        if (ret == 0)
        {
            is_timeout_ = true;
            std::cout << "timeout return " << std::endl;
            return;
        }
        else if (ret == -1)
        {
            std::cout << "select error, errno: " << errno << std::endl;
            return;
        }

        char recv_buf[4096] = {0};
        int recv_size = 0;
        if (-1 == (recv_size = recv(*fd, recv_buf, sizeof(recv_buf), 0)))
        {
            std::cout << "recv failed! errno: " << errno << std::endl;
            return;
        }

        if (!response->ParseFromArray(recv_buf, recv_size))
        {
            std::cout << "response parse failed!" << std::endl;
            return;
        }
    }

    int MoRpcChannel::Select(int &fd)
    {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(fd, &read_fds);

        struct timeval timeout;
        timeout.tv_sec = timeout_sec_;
        timeout.tv_usec = 0;

        return select(fd + 1, &read_fds, NULL, NULL, &timeout);
    }
}