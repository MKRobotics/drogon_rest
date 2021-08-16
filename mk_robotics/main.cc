#include <drogon/drogon.h>

#include "scheduler/PeriodicScheduler.h"
#include "ws_manager/WebSocketManager.h"
#include "status_provider/DummyStatusProvider.h"
#include "controllers/mk_robotics_v1_WsDummmy.h"
#include "controllers/mk_robotics_api_v1_MotorsController.h"
#include "data_mappings/Motors.h"

int main()
{
    mk_robotics::ws_manager::WebSocketManager ws_manager;
    mk_robotics::PeriodicScheduler scheduler;
    mk_robotics::DummyStatusProvider dummy_status_provider;

    auto wsHandler = std::make_shared<mk_robotics::api::v1::WsDummmy>(&ws_manager, &dummy_status_provider);

    std::map<std::string, float> dummy_motors {{"fl", 0.0f},{"fr", 0.0f},{"br", 0.0f},{"bl", 0.0f}};
    mk_robotics::data_mapping::Motors motors {dummy_motors};
    auto motorsHandler = std::make_shared<mk_robotics::api::v1::Motors>(&motors);

    scheduler.AddTask(
        "NotifyClients", [&ws_manager, &dummy_status_provider]

        { ws_manager.NotifyAll(dummy_status_provider.GetStatus()); },
        boost::posix_time::seconds(1));

    std::thread web_service([&wsHandler, &motorsHandler]
                            { drogon::app().addListener("0.0.0.0", 80).registerController(wsHandler).registerController(motorsHandler).setLogLevel(trantor::Logger::LogLevel::kDebug).run(); });

    scheduler.Run();

    if (web_service.joinable())
    {
        web_service.join();
    }

    return 0;
}
