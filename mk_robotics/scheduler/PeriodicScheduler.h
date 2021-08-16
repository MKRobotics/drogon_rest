#pragma once

#include "PeriodicTask.h"

namespace mk_robotics
{
    class PeriodicScheduler
    {
    public:
        void Run();
        void AddTask(std::string const &name, PeriodicTask::handler_fn const &task, boost::posix_time::time_duration interval);

    private:
        boost::asio::io_service io_service_;
        std::vector<std::unique_ptr<PeriodicTask>> tasks_;
    };
}