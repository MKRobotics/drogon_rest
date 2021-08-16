#include "mk_robotics_v1_WsDummmy.h"
using namespace mk_robotics::api::v1;

WsDummmy::WsDummmy(ws_manager::WebSocketManager *manager, IStatusProvider *statusProvider)
    : manager_(manager),
      status_provider_(statusProvider)
{
}

void WsDummmy::handleNewMessage(const WebSocketConnectionPtr &wsConnPtr, std::string &&message, const WebSocketMessageType &type)
{
    LOG_DEBUG << "Message " << message;
}
void WsDummmy::handleNewConnection(const HttpRequestPtr &req, const WebSocketConnectionPtr &wsConnPtr)
{
    manager_->Add(wsConnPtr);
}
void WsDummmy::handleConnectionClosed(const WebSocketConnectionPtr &wsConnPtr)
{
    manager_->Remove(wsConnPtr);
}
