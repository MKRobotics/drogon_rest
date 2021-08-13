#pragma once

#include <string>

namespace mk_robotics
{
    class IStatusProvider
    {
    public:
        virtual std::string getStatus() = 0;
        virtual ~IStatusProvider() = default;
    };
}
