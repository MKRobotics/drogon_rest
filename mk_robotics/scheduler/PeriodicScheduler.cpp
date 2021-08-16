#include "PeriodicScheduler.h"

namespace mk_robotics
{

    void PeriodicScheduler::Run()
    {
        io_service_.run();
    }

    void PeriodicScheduler::AddTask(std::string const &name, PeriodicTask::handler_fn const &task, boost::posix_time::time_duration interval)
    {
        tasks_.push_back(std::make_unique<PeriodicTask>(std::ref(io_service_), name, interval, task));
    }
}