#include "PeriodicTask.h"

namespace mk_robotics
{
    PeriodicTask::PeriodicTask(boost::asio::io_service &io_service, std::string const &name, boost::posix_time::time_duration interval, handler_fn task)
        : io_service_(io_service), interval_(interval), task_(task), name_(name), timer_(io_service)
    {
        io_service.post(boost::bind(&PeriodicTask::Start, this));
    }

    void PeriodicTask::Execute(boost::system::error_code const &e)
    {
        if (e != boost::asio::error::operation_aborted)
        {
            task_();
            timer_.expires_at(timer_.expires_at() + interval_);
            StartWait();
        }
    }

    void PeriodicTask::Start()
    {
        timer_.expires_from_now(interval_);
        StartWait();
    }

    void PeriodicTask::StartWait()
    {
        timer_.async_wait(boost::bind(&PeriodicTask::Execute, this, boost::asio::placeholders::error));
    }
}
