#include "mk_robotics_v1_WsDummmy.h"
using namespace mk_robotics::api::v1;

void WsDummmy:: handleNewMessage(const WebSocketConnectionPtr &wsConnPtr, std::string &&message, const WebSocketMessageType &type)
{
    std::ostringstream oss;
    oss << "MSG: " << message;
    wsConnPtr->send(oss.str());
}
void WsDummmy::handleNewConnection(const HttpRequestPtr &req, const WebSocketConnectionPtr &wsConnPtr)
{
    wsConnPtr->send("OK XD");
}
void WsDummmy::handleConnectionClosed(const WebSocketConnectionPtr &wsConnPtr)
{
    LOG_DEBUG << "Disconnected ";
}
