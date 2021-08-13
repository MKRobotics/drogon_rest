#include <drogon/drogon.h>

#include "scheduler/PeriodicScheduler.h"
#include "ws_manager/WebSocketManager.h"
#include "status_provider/DummyStatusProvider.h"
#include "controllers/mk_robotics_v1_WsDummmy.h"

int main()
{
    mk_robotics::PeriodicScheduler scheduler;
    mk_robotics::ws_manager::WebSocketManager wsManager;
    mk_robotics::DummyStatusProvider dummyStatusProvider;

    auto wsHandler = std::make_shared<mk_robotics::api::v1::WsDummmy>(&wsManager, &dummyStatusProvider);

    scheduler.addTask(
        "NotifyClients", [&wsManager, &dummyStatusProvider]

        {
                             wsManager.notifyAll(dummyStatusProvider.getStatus());
        },
        boost::posix_time::seconds(1));

    std::thread web_service([&wsHandler]
                            { drogon::app().addListener("0.0.0.0", 80).registerController(wsHandler).run(); });

    scheduler.run();

    if (web_service.joinable())
    {
        web_service.join();
    }

    return 0;
}
