#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
namespace mk_robotics
{
  namespace v1
  {
    class Dummy : public drogon::HttpController<Dummy>
    {
    public:
      METHOD_LIST_BEGIN
      METHOD_ADD(Dummy::getString, "/data?data={1}", Get);
      METHOD_LIST_END

      void getString(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback,
                     const std::string &data);
    };
  }
}
