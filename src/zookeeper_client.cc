#include "zookeeper_client.h"
#include "morpc_application.h"
#include "logger.h"

#include <semaphore.h>

namespace morpc
{

    /// @brief zookeeper 服务端给客户端的通知回调
    void WatcherCallback(zhandle_t *zh, int type,
                         int state, const char *path, void *watcherCtx)
    {
        if (type == ZOO_SESSION_EVENT) // 回调的消息类型是和会话相关的事件
        {
            if (state == ZOO_CONNECTED_STATE) // 连接成功
            {
                sem_t *sem = (sem_t *)zoo_get_context(zh);
                sem_post(sem);
            }
        }
    }

    ZookeeperClient::ZookeeperClient() : zhandle_(nullptr)
    {
    }

    ZookeeperClient::~ZookeeperClient()
    {
        if (zhandle_ != nullptr)
        {
            zookeeper_close(zhandle_);
        }
    }

    void ZookeeperClient::Start()
    {
        std::string host = MoRpcApplication::GetInstance().GetConfig().Select("zookeeper_ip");
        std::string port = MoRpcApplication::GetInstance().GetConfig().Select("zookeeper_port");
        std::string connstr = host;
        connstr += ":";
        connstr += port;

        zhandle_ = zookeeper_init(connstr.c_str(), WatcherCallback, 30000, nullptr, nullptr, 0);
        if (nullptr == zhandle_)
        {
            LOG_ERROR("zookeeper init failed!");
            exit(EXIT_FAILURE);
        }

        sem_t sem;
        sem_init(&sem, 0, 0);
        zoo_set_context(zhandle_, &sem);

        sem_wait(&sem);
        LOG_INFO("zookeeper init success!");
        sem_close(&sem);
    }

    void ZookeeperClient::Create(const char *path, const char *data, int datalen, int state)
    {
        char path_buffer[128] = {0};
        int bufferlen = sizeof(path_buffer);
        int flag = zoo_exists(zhandle_, path, 0, nullptr);
        if (flag == ZNONODE) // 该znode节点不存在
        {
            std::stringstream ss;
            flag = zoo_create(zhandle_, path, data, datalen, &ZOO_OPEN_ACL_UNSAFE, state, path_buffer, bufferlen);
            if (flag == ZOK)
            {
                ss << "znode create success! path: " << path;
                LOG_INFO(ss.str());
            }
            else
            {
                ss << "zcode create failed! path: " << path << " flag: " << flag;
                LOG_ERROR(ss.str());
                exit(EXIT_FAILURE);
            }
        }
    }

    std::string ZookeeperClient::GetData(const char *path)
    {
        char buffer[1024] = {0};
        int bufferlen = sizeof(buffer);
        int flag = zoo_get(zhandle_, path, 0, buffer, &bufferlen, nullptr);
        if (flag != ZOK)
        {
            std::stringstream ss;
            ss << "get znode data failed, path: " << path;
            LOG_INFO(ss.str());
            return "";
        }
        else
        {
            return buffer;
        }
    }
}