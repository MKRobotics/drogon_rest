#pragma once

#include "PeriodicTask.h"

namespace mk_robotics
{
    class PeriodicScheduler
    {
    public:
        void run();
        void addTask(std::string const &name, PeriodicTask::handler_fn const &task, boost::posix_time::time_duration interval);

    private:
        boost::asio::io_service io_service;
        std::vector<std::unique_ptr<PeriodicTask>> tasks;
    };
}