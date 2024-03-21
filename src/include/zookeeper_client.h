#ifndef __ZOOKEEPER_CLIENT_H__
#define __ZOOKEEPER_CLIENT_H__

/*
 * 封装的 zookeeper 客户端的类
 */

#include <string>
#include <zookeeper/zookeeper.h>

namespace morpc
{
    class ZookeeperClient
    {
    public:
        ZookeeperClient();
        ~ZookeeperClient();

        /// @brief zookeeper 客户端启动连接 zookeeper服务器
        void Start();

        /// @brief 在zookeeper服务器上创建znode节点
        /// @param path znode路径
        /// @param data znode存储的数据
        /// @param datalen 存储的数据大小
        /// @param state 是否创建为永久性节点还是临时性节点(0:永久<默认> EPHEMERAL: 临时性)
        void Create(const char *path, const char *data, int datalen, int state = 0);

        /// @brief 在zookeeper服务器根据path获取znode节点上的值
        /// @param path znode节点路径
        /// @return 存在返回znode节点上的值, 不存在返回空串
        std::string GetData(const char *path);

    private:
        /// @brief zk客户端句柄
        zhandle_t *zhandle_;
    };
}

#endif