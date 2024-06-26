#include <iostream>
#include <string>

#include "user.pb.h"
#include "morpc_application.h"
#include "morpc_provider.h"

using namespace test;
using namespace std;

/*
 * UserService 是一个本地服务，提供两个本地方法，Login和GetUserLists
 */

/// @brief rpc服务提供者
class UserService : public UserServiceRPC
{
public:
    UserService() {}
    ~UserService() {}

    bool Login(std::string username, std::string password)
    {
        cout << "doing local service: Login" << endl;
        cout << "username: " << username << " password: " << password << endl;
        return false;
    }

    bool Register(uint32_t id, std::string username, std::string password)
    {
        cout << "doing local service: Register" << endl;
        cout << "id: " << id << " username: " << username << " password: " << password << endl;
        return true;
    }

    /// @brief 重写UserServiceRPC的虚函数 该方法是框架直接调用
    /// caller ===>(发送rpc请求) Login(LoginRequest) ===> 网络I/O模块 ===> callee
    /// callee ===>(框架先接收到rpc请求)  Login(LoginRequest) ===> 框架回调到下面的重写方法
    virtual void Login(::google::protobuf::RpcController *controller,
                       const ::test::LoginRequest *request,
                       ::test::LoginResponse *response,
                       ::google::protobuf::Closure *done) override
    {
        // 直接取出数据，框架做过反序列化
        string username = request->username();
        string password = request->password();

        // 本地业务
        bool ret = Login(username, password);

        // 响应结果写入LoginResponse
        response->set_success(ret);
        test::ResultCode *code = response->mutable_result();
        if (ret)
        {
            code->set_errcode(0);
            code->set_errmsg("login success!");
        }
        else
        {
            code->set_errcode(400);
            code->set_errmsg("login failed!");
        }

        // 执行回调函数, 执行响应对象数据的序列化和网络发送(框架完成)
        done->Run();
    }

    void Register(::google::protobuf::RpcController *controller,
                  const ::test::RegisterRequest *request,
                  ::test::RegisterResponse *response,
                  ::google::protobuf::Closure *done) override
    {
        uint32_t id = request->id();
        string username = request->username();
        string password = request->password();

        bool ret = Register(id, username, password);
        response->set_success(ret);
        test::ResultCode *code = response->mutable_result();
        if (ret)
        {
            code->set_errcode(0);
            code->set_errmsg("register success!");
        }
        else
        {
            code->set_errcode(400);
            code->set_errmsg("register failed!");
        }

        done->Run();
    }

private:
};

int main(int argc, char *argv[])
{
    // 框架初始化
    morpc::MoRpcApplication::Init(argc, argv);

    // 把UserService对象发布到rpc节点上
    morpc::MoRpcProvider provider;
    auto user_server = new UserService();
    provider.NotifyService(user_server);
    //  启动一个rpc服务发布节点
    provider.set_thread_num(6);
    provider.Run();

    return 0;
}