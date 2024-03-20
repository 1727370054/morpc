#include <iostream>

#include "morpc_application.h"
#include "morpc_channel.h"
#include "morpc_controller.h"
#include "user.pb.h"

using namespace test;
using namespace std;

/*
 * 对于生成的*_Stub类, 调用远程的方法, 其实是通过传入的RpcChannel* channel参数,
 * 再由传入的channel调用它的CallMethod方法, 框架需要在 channel 集中实现方法调用的参数序列化和网络发送
 */

int main(int argc, char *argv[])
{
    // 整个程序启动后, 使用morpc框架的rpc调用服务, 一定需要调用框架初始化函数(只需要初始化一次)
    morpc::MoRpcApplication::Init(argc, argv);

    /*************************** 演示调用rpc方法Login() ***********************************/

    auto channel = new morpc::MoRpcChannel();
    UserServiceRPC_Stub stub(channel);
    // rpc方法请求参数
    LoginRequest request;
    request.set_username("zhang san");
    request.set_password("123456");

    // rpc方法的响应
    LoginResponse response;

    // 设置rpc调用超时时间, 需要在调用方法之间设置
    channel->set_timeout(3);

    // 定义一个控制对象
    morpc::MoRpcController controller;

    // 发起rpc调用, 同步rpc调用 MoRpcChannel::CallMethod();
    stub.Login(&controller, &request, &response, nullptr);

    if (controller.Failed())
    {
        cout << controller.ErrorText() << endl;
    }
    else
    {
        if (channel->is_timeout())
        {
            std::cout << "rpc calls return on a timeout" << std::endl;
            return 0;
        }

        // rpc调用完成, 读取调用结果
        if (response.success()) // 成功
        {
            cout << "login success! response: " << response.success() << endl;
        }
        else
        {
            cout << "login failed! errcode: " << response.result().errcode()
                 << " errmsg: " << response.result().errmsg() << endl;
        }
    }

    /*************************** 演示调用rpc方法Register() ***********************************/
    RegisterRequest req;
    req.set_id(123456);
    req.set_username("test register");
    req.set_password("6666");
    RegisterResponse res;
    stub.Register(&controller, &req, &res, nullptr);

    if (controller.Failed())
    {
        cout << controller.ErrorText() << endl;
    }
    else
    {
        if (channel->is_timeout())
        {
            std::cout << "rpc calls return on a timeout" << std::endl;
            return 0;
        }

        if (res.success())
        {
            cout << "register success! response: " << res.success() << endl;
        }
        else
        {
            cout << "register failed! errcode: " << res.result().errcode()
                 << " errmsg: " << res.result().errmsg() << endl;
        }
    }

    delete channel;
    return 0;
}