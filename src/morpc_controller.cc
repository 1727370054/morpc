#include "morpc_controller.h"

namespace morpc
{
    void MoRpcController::Reset()
    {
        failed_ = false;
        err_text_ = "";
    }

    bool MoRpcController::Failed() const
    {
        return failed_;
    }

    std::string MoRpcController::ErrorText() const
    {
        return err_text_;
    }

    void MoRpcController::StartCancel()
    {
        canceled_ = true;
        if (onCancelCallback_ != nullptr)
        {
            onCancelCallback_->Run();
            onCancelCallback_ = nullptr; // 确保回调只被执行一次
        }
    }

    void MoRpcController::SetFailed(const std::string &reason)
    {
        failed_ = true;
        err_text_ = reason;
    }

    bool MoRpcController::IsCanceled() const
    {
        return canceled_;
    }

    void MoRpcController::NotifyOnCancel(google::protobuf::Closure *callback)
    {
        onCancelCallback_ = callback;
    }
}