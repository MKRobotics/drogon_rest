#pragma once

#include <drogon/WebSocketController.h>

#include "ws_manager/WebSocketManager.h"
#include "status_provider/IStatusProvider.h"

using namespace drogon;
namespace mk_robotics
{
  namespace api
  {
    namespace v1
    {
      class WsDummmy : public drogon::WebSocketController<WsDummmy, false>
      {
      public:
        WsDummmy(ws_manager::WebSocketManager *manager, IStatusProvider *statusProvder);
        virtual void handleNewMessage(const WebSocketConnectionPtr &,
                                      std::string &&,
                                      const WebSocketMessageType &) override;
        virtual void handleNewConnection(const HttpRequestPtr &,
                                         const WebSocketConnectionPtr &) override;
        virtual void handleConnectionClosed(const WebSocketConnectionPtr &) override;
        WS_PATH_LIST_BEGIN
        WS_PATH_ADD("/data");
        WS_PATH_LIST_END
      private:
        ws_manager::WebSocketManager *manager_;
        IStatusProvider *status_provider_;
      };
    }
  }
}
