#include <string>
#include <iostream>

#include "WdTypes.hxx"
#include "IPC/IpcChannel.hxx"

auto main(int argc, const char **argv) -> int {
    auto channel = Ipc::Channel<std::string, 32>("Testing");
    return 0;
}
