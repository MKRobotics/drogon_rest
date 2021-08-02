#include "mk_robotics_v1_Dummy.h"
#include <random>

using namespace mk_robotics::api::v1;

void Dummy::getString(const HttpRequestPtr &req,
                      std::function<void(const HttpResponsePtr &)> &&callback,
                      const std::string &data)
{
    LOG_DEBUG << "Data  " << data;
    Json::Value ret;
    ret["result"] = "ok";
    ret["data"] = data;
    std::random_device rdev;
    std::mt19937 rgen(rdev());
    std::uniform_int_distribution<int> idist(0,10);
    ret["id"] = idist(rgen);
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}