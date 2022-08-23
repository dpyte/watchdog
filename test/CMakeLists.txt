
find_package (GTest)

include_directories ("${CMAKE_SOURCE_DIR}/src/")
include_directories ("${CMAKE_SOURCE_DIR}/src/include")

# === Parsing ===
set (TestParsingSources
	parsing/TestXmlSystemConfig.cxx
)

add_executable (
	RunTestParsing
	${TestParsingSources}
)

target_link_libraries (
	RunTestParsing
	WdCamera
	gtest
	gtest_main
)

add_test (
	NAME RunTestParsing
	COMMAND RunTestParsing
)

# === Result ===
set (
	TestResults
	TestResult.cxx
)

add_executable (
	RunTestResults
	${TestResults}
)

target_link_libraries (
	RunTestResults
	gtest
	gtest_main
)

target_include_directories (RunTestResults INTERFACE "${CMAKE_SOURCE_DIR}/src/include")

add_test (
	Name RunTestResults
	CMD  RunTestResults
)

