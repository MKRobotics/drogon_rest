#pragma once

#include "PeriodicTask.h"

class PeriodicScheduler
{
public:
    void run()
    {
        io_service.run();
    }

    void addTask(std::string const &name, PeriodicTask::handler_fn const &task, boost::posix_time::time_duration interval)
    {
        tasks.push_back(std::make_unique<PeriodicTask>(std::ref(io_service), name, interval, task));
    }

private:
    boost::asio::io_service io_service;
    std::vector<std::unique_ptr<PeriodicTask>> tasks;
};