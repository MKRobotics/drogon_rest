#include "WebSocketManager.h"
namespace mk_robotics
{
    namespace ws_manager
    {
        void WebSocketManager::NotifyAll(const std::string &msg)
        {
            ForEach([&msg](const auto &connection)
                    { connection->send(msg); });
        }
        void WebSocketManager::Add(const drogon::WebSocketConnectionPtr &client)
        {
            clients_.push_back(client);
        }
        void WebSocketManager::Remove(const drogon::WebSocketConnectionPtr &client)
        {
            clients_.erase(std::remove_if(clients_.begin(), clients_.end(), [&client](const auto &connection)
                           { return connection == client;}), clients_.end());
        }

    }
}