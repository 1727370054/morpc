#ifndef __MORCP_CONTROLLER_H__
#define __MORCP_CONTROLLER_H__

#include <google/protobuf/service.h>
#include <string>

namespace morpc
{
    class MoRpcController : public google::protobuf::RpcController
    {
    public:
        virtual void Reset() override;

        virtual bool Failed() const override;

        virtual std::string ErrorText() const override;

        virtual void StartCancel() override;

        virtual void SetFailed(const std::string &reason) override;

        virtual bool IsCanceled() const override;

        virtual void NotifyOnCancel(google::protobuf::Closure *callback) override;

    private:
        /// @brief RPC方法执行过程中的状态
        bool failed_ = false;
        /// @brief RPC方法执行过程中的错误信息
        std::string err_text_ = "";
        /// @brief 用来标记RPC调用是否已被取消
        bool canceled_ = false;
        /// @brief 存储取消时需要调用的回调函数
        google::protobuf::Closure *onCancelCallback_ = nullptr;
    };
}

#endif