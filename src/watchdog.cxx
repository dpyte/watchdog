#include <services.hxx>

auto main(int argc, const char **argv) -> int {
    auto core = WdService::CoreService(WdService::Names::Cored);
    std::fprintf(stderr, "Starting watchdog core\ncore status: %s\n", core.get_status_as_str());
    return 0;
}