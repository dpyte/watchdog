
#include "IPC/IpcObject.hxx"
#include "IPC/IpcChannel.hxx"

#include <gtest/gtest.h>

TEST(TestIpc, TestIpcServer) {
    auto ipcobj = IpcDetails::IpcServer<String, 8>("Test");
    auto const isize = ipcobj.size();
    ASSERT_EQ(isize, 16);
}