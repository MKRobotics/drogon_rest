#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace mk_robotics
{
    class PeriodicTask
    {
    public:
        using handler_fn = std::function<void()>;

        PeriodicTask(boost::asio::io_service &io_service, std::string const &name, boost::posix_time::time_duration interval, handler_fn task);
        void execute(boost::system::error_code const &e);
        void start();

    private:
        void start_wait();
        boost::asio::io_service &ioService;
        boost::asio::deadline_timer timer;
        handler_fn task;
        std::string name;
        boost::posix_time::time_duration interval;
    };
}