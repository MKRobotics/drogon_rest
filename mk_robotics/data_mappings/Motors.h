#pragma once

#include <drogon/drogon.h>

namespace mk_robotics
{
    namespace data_mapping
    {
        struct Motors
        {
            std::map<std::string, float> values;
        };
    }
}

namespace drogon
{
    namespace dm = mk_robotics::data_mapping;
    template <>
    inline dm::Motors fromRequest(const HttpRequest &req)
    {
        auto json = req.getJsonObject();
        dm::Motors motors;
        if (json)
        {
            std::cout << "parse" << std::endl;
            for (const auto &motor : (*json))
            {
                motors.values[(*json)["name"].asString()] = (*json)["name"].asFloat();
            }
        }
        return motors;
    }
}