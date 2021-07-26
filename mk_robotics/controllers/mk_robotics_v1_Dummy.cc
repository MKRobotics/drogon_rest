#include "mk_robotics_v1_Dummy.h"
using namespace mk_robotics::v1;

void Dummy::getString(const HttpRequestPtr &req,
                      std::function<void(const HttpResponsePtr &)> &&callback,
                      const std::string &data)
{
    LOG_DEBUG << "Data  " << data;
    Json::Value ret;
    ret["result"] = "ok";
    ret["data"] = data;
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}