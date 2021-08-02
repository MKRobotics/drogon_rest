#include <drogon/drogon.h>
#include "scheduler/PeriodicScheduler.h"
int main()

{

    PeriodicScheduler scheduler;
    scheduler.addTask(
        "CPU", [] { std::cout << "XD\n"; }, boost::posix_time::seconds(10));
    scheduler.addTask(
        "Memory", [] { std::cout << "XDXD\n"; }, boost::posix_time::microseconds(10000));

    std::thread([] {
        drogon::app().addListener("0.0.0.0", 80);
        drogon::app().run();
    }).detach();
    
    scheduler.run();

    return 0;
}
