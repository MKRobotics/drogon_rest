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
        void Execute(boost::system::error_code const &e);
        void Start();

    private:
        void StartWait();
        boost::asio::io_service &io_service_;
        boost::asio::deadline_timer timer_;
        handler_fn task_;
        std::string name_;
        boost::posix_time::time_duration interval_;
    };
}