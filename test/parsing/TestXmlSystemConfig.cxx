
#include "vision/Xml.hxx"

#include <gtest/gtest.h>

TEST(TestSystemConfig, TestDisplayConfig) {
    auto sysconf_display = WdData::parse_system_config(
            "/Users/dpyte/dev/repos/ReckonLabs/WatchDog/test/parsing/test_system_info.xml");

    const auto second_field = sysconf_display.second;
    ASSERT_EQ(second_field.empty(), true);

    const auto disp_config = *sysconf_display.first; // sysconf_display.first;
    ASSERT_EQ(disp_config.height, 4096);
    ASSERT_EQ(disp_config.width, 2144);

    ASSERT_NE(disp_config.height, 0);
    ASSERT_NE(disp_config.width, 9);

    ASSERT_EQ(disp_config.document, nullptr);
}
