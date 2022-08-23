#include "Result.hxx"
#include "WdTypes.hxx"
#include <gtest/gtest.h>

Result<usize> contains_error() { return ReturnResult(10, "Check contains_error"); }

Result<String> contains_no_error() { return ReturnResult("Contains no_error", String{}); }

TEST(TestResult, TestCheckResultFail) {
    const auto error = contains_error();
    ASSERT_EQ(CheckError(error), true);
}

TEST(TestResult, TestCheckResultSuccess) {
    const auto noerr = contains_no_error();
    ASSERT_EQ(CheckError(noerr), false);
}
