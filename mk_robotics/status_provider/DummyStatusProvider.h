#pragma once

#include <string>

#include "IStatusProvider.h"

namespace mk_robotics
{
    class DummyStatusProvider : public IStatusProvider
    {
    public:
        std::string getStatus() override;
    };
}