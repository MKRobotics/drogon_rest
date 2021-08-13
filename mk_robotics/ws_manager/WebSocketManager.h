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
            void forEach(F &&f)
            {
                std::for_each(_clients.begin(), _clients.end(), f);
            }
            
            void notifyAll(const std::string &msg);
            void add(const drogon::WebSocketConnectionPtr &);
            

        private:
            std::vector<drogon::WebSocketConnectionPtr> _clients;
        };
    }
}