
#include <Ui/Window.hxx>
#include <gtest/gtest.h>


TEST(TestUi, TestUiWindow) {
    auto window = Ui::Window("Test", 123, 123);
    const auto wwindow = window.g_window();
    std::fprintf(stderr, "Error status: %d\n", CheckError(wwindow));
    ASSERT_EQ(CheckError(wwindow), false);
}
