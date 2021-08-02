#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>

class PeriodicTask
{
public:
    using handler_fn = std::function<void()>;

    PeriodicTask(boost::asio::io_service &io_service, std::string const &name, boost::posix_time::time_duration interval, handler_fn task)
        : ioService(io_service), interval(interval), task(task), name(name), timer(io_service)
    {
        ioService.post(boost::bind(&PeriodicTask::start, this));
    }

    void execute(boost::system::error_code const &e)
    {
        if (e != boost::asio::error::operation_aborted)
        {
            task();
            timer.expires_at(timer.expires_at() + interval);
            start_wait();
        }
    }

    void start()
    {
        timer.expires_from_now(interval);
        start_wait();
    }

private:
    void start_wait()
    {
        timer.async_wait(boost::bind(&PeriodicTask::execute, this, boost::asio::placeholders::error));
    }

private:
    boost::asio::io_service &ioService;
    boost::asio::deadline_timer timer;
    handler_fn task;
    std::string name;
    boost::posix_time::time_duration interval;
};