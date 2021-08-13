#include "WebSocketManager.h"

namespace mk_robotics
{
    namespace ws_manager
    {
        void WebSocketManager::notifyAll(const std::string &msg)
        {
            forEach([&msg](const auto &connection)
                    { connection->send(msg); });
        }
        void WebSocketManager::add(const drogon::WebSocketConnectionPtr &client)
        {
            _clients.push_back(client);
        }
    }
}