#pragma once

#include <string>

namespace mk_robotics
{
    class IStatusProvider
    {
    public:
        virtual std::string GetStatus() = 0;
        virtual ~IStatusProvider() = default;
    };
}
