#include "PeriodicTask.h"

namespace mk_robotics
{
    PeriodicTask::PeriodicTask(boost::asio::io_service &io_service, std::string const &name, boost::posix_time::time_duration interval, handler_fn task)
        : ioService(io_service), interval(interval), task(task), name(name), timer(io_service)
    {
        ioService.post(boost::bind(&PeriodicTask::start, this));
    }

    void PeriodicTask::execute(boost::system::error_code const &e)
    {
        if (e != boost::asio::error::operation_aborted)
        {
            task();
            timer.expires_at(timer.expires_at() + interval);
            start_wait();
        }
    }

    void PeriodicTask::start()
    {
        timer.expires_from_now(interval);
        start_wait();
    }

    void PeriodicTask::start_wait()
    {
        timer.async_wait(boost::bind(&PeriodicTask::execute, this, boost::asio::placeholders::error));
    }
}
