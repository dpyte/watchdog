#include <services.hxx>
#include <spdlog/spdlog.h>

auto main(int argc, const char **argv) -> int {
    spdlog::warn("Starting watchdog core");
    auto core = WdService::CoreService(WdService::Names::Cored);
    return 0;
}