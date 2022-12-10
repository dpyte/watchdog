#include <string_view>
#include <services.hxx>
#include <spdlog/spdlog.h>

/// Kick-starts the system
auto main(int argc, const char **argv) -> int {
    // Stop wasting resources you imbecile
    if (argc <= 1) {
        spdlog::warn("program called without any arguments. quitting ...");
        return -1;
    }

    i32 p_return_status = -1;
    if (argv[1] == std::string_view("--start")) {
        spdlog::warn("Starting watchdog core");

        auto core = WdService::CoreService(WdService::Names::Cored);
        core.activate();
        p_return_status = core.get_exit_status();
    }
    return p_return_status;
}