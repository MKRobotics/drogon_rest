#pragma once

#include <drogon/WebSocketConnection.h>

#include <vector>
#include <algorithm>
#include <string>

namespace mk_robotics
{
    namespace ws_manager
    {
        class WebSocketManager
        {
        public:
            template <typename F>
            void ForEach(F &&f)
            {
                std::for_each(clients_.begin(), clients_.end(), f);
            }

            void NotifyAll(const std::string &msg);
            void Add(const drogon::WebSocketConnectionPtr &);
            void Remove(const drogon::WebSocketConnectionPtr &);

        private:
            std::vector<drogon::WebSocketConnectionPtr> clients_;
        };
    }
}