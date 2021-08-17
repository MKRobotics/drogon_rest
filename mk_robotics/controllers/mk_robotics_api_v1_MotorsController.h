#pragma once
#include <drogon/HttpController.h>
#include "../data_mappings/Motors.h"

using namespace drogon;

namespace mk_robotics
{
  namespace api
  {
    namespace v1
    {
      namespace dm = mk_robotics::data_mapping;
      class Motors : public drogon::HttpController<Motors, false>
      {
      public:
        Motors(dm::Motors *motors);

        METHOD_LIST_BEGIN
        METHOD_ADD(Motors::SetMotors, "", Post);
        METHOD_ADD(Motors::GetMotors, "", Get);
        METHOD_LIST_END

        void SetMotors(const HttpRequestPtr &req,
                       std::function<void(const HttpResponsePtr &)> &&callback,
                       dm::Motors &&motors) const;
        void GetMotors(const HttpRequestPtr &req,
                       std::function<void(const HttpResponsePtr &)> &&callback) const;

      private:
        dm::Motors *motors_;
      };
    }
  }
}
