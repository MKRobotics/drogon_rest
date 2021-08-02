#pragma once
#include <drogon/WebSocketController.h>
using namespace drogon;
namespace mk_robotics
{
  namespace api{
  
  namespace v1
  {
    class WsDummmy : public drogon::WebSocketController<WsDummmy>
    {
    public:
      virtual void handleNewMessage(const WebSocketConnectionPtr &,
                                    std::string &&,
                                    const WebSocketMessageType &) override;
      virtual void handleNewConnection(const HttpRequestPtr &,
                                       const WebSocketConnectionPtr &) override;
      virtual void handleConnectionClosed(const WebSocketConnectionPtr &) override;
      WS_PATH_LIST_BEGIN
      WS_PATH_ADD("/data");
      WS_PATH_LIST_END
    };
  }
  }
}
