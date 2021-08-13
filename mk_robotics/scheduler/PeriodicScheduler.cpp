#include "PeriodicScheduler.h"

namespace mk_robotics
{

    void PeriodicScheduler::run()
    {
        io_service.run();
    }

    void PeriodicScheduler::addTask(std::string const &name, PeriodicTask::handler_fn const &task, boost::posix_time::time_duration interval)
    {
        tasks.push_back(std::make_unique<PeriodicTask>(std::ref(io_service), name, interval, task));
    }
}