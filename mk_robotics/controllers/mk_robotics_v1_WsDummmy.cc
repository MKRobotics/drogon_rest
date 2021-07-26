#include "mk_robotics_v1_WsDummmy.h"
using namespace mk_robotics::v1;
void WsDummmy::handleNewMessage(const WebSocketConnectionPtr &wsConnPtr, std::string &&message, const WebSocketMessageType &type)
{
    wsConnPtr->send(message);
}
void WsDummmy::handleNewConnection(const HttpRequestPtr &req, const WebSocketConnectionPtr &wsConnPtr)
{
    wsConnPtr->send("Connected to dummy serrver");
}
void WsDummmy::handleConnectionClosed(const WebSocketConnectionPtr &wsConnPtr)
{
    LOG_DEBUG << "Disconnected  ";
}
