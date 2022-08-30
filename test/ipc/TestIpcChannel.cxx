
#include "IPC/IpcObject.hxx"
#include "IPC/IpcChannel.hxx"

#include <gtest/gtest.h>

TEST(TestIpc, TestIpcServer) {
    auto ipcobj = IpcDetails::IpcServer<String>("Test");
    // This test is expected to fail
}

TEST(TestIpc, TestIpcServerClientCheck) {
    auto ipcobj = IpcDetails::IpcServer<String>("TestIpcServerClientCheck");
    auto const subscribe = ipcobj.subscribe("TestSubscribe");
    const auto return_check = CheckError(subscribe);
    ASSERT_EQ(return_check, true);
}

TEST(TestIpc, TestIpcClientName) {
    auto ipcobj = IpcDetails::IpcServer<String>("TestIpcServerClientCheck");
    auto const subscribe_result = ipcobj.subscribe("TestSubscribe");
    auto const return_check = CheckError(subscribe_result);
    ASSERT_EQ(return_check, true);

    if (not return_check) { 
        std::runtime_error(ResultMessage(subscribe_result).c_str());
    }
    auto const subscribe = ResultObject(subscribe_result);
    ASSERT_EQ("TestSubscribe", subscribe.client_name());
}
