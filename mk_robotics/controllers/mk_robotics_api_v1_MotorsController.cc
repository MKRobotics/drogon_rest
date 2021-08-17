#include "mk_robotics_api_v1_MotorsController.h"
#include "../utils/utils.h"
using namespace mk_robotics::api::v1;

Motors::Motors(dm::Motors *motors)
    : motors_(motors)
{
}

void Motors::SetMotors(const HttpRequestPtr &req,
                       std::function<void(const HttpResponsePtr &)> &&callback,
                       dm::Motors &&motors) const
{
    Json::Value missed, changed;
    for (const auto &newMotorData : motors.values)
    {
        auto motorIt = motors_->values.find(newMotorData.first);
        if (motorIt != motors_->values.end())
        {
            LOG_DEBUG << "Motor " << newMotorData.first << " changed from " << motorIt->second << " to " << newMotorData.second;
            motorIt->second = newMotorData.second;
            changed.append(newMotorData.first);
        }
        else
        {
            LOG_INFO << "Undefined motor " << newMotorData.first;
            missed.append(newMotorData.first);
        }
    }

    Json::Value ret;
    ret["result"] = "ok";
    ret["missed"] = missed;
    ret["changed"] = changed;
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
void Motors::GetMotors(const HttpRequestPtr &req,
                       std::function<void(const HttpResponsePtr &)> &&callback) const
{
    Json::Value ret;
    Json::Value motors;
    for (const auto &motor : motors_->values)
    {
        Json::Value motor_data;
        motor_data["id"] = motor.first;
        motor_data["value"] = motor.second;
        motors.append(motor_data);
    }
    ret["motors"] = motors;
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
