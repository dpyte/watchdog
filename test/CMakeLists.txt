
find_package (GTest)

include_directories ("${CMAKE_SOURCE_DIR}/src/")
include_directories ("${CMAKE_SOURCE_DIR}/src/include")

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
