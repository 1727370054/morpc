#include <iostream>
#include <string>
#include "test.pb.h"

using namespace test;
using namespace std;

/*
 一个service声明了可以被客户端调用的方法，
 每个方法指定了请求消息类型和响应消息类型。service定义了服务的接口规范，但是不实现任何逻辑。
 实际的逻辑实现是依赖于使用Protobuf的RPC框架
 *****************************************************************************************
 生成的C++代码，UserServiceRPC是一个类，继承google::protobuf::Servic这个基类，用于rpc服务提供者
 生成的UserServiceRPC_Stub继承UserServiceRPC, 用于rpc服务消费者
*/

/// @brief 测试protobuf
int main(int argc, char *argv[])
{
    GetFriendListsResponse rsp;
    ResultCode *rc = rsp.mutable_result();
    rc->set_errcode(502);

    User *user1 = rsp.add_friend_list();
    user1->set_name("zhang san");
    user1->set_age(20);
    user1->set_sex(User::MAN);

    User *user2 = rsp.add_friend_list();
    user2->set_name("li si");
    user2->set_age(22);
    user2->set_sex(User::MAN);

    std::cout << rsp.DebugString() << std::endl;

    return 0;
}