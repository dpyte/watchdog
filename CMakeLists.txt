cmake_minimum_required (VERSION 3.18)

project (
	WatchDog
	CXX
)

if (${CMAKE_SOURCE_DIR} STREQUAL {CMAKE_BINARY_DIR})
	message (FATAL_ERROR "In-source build is not allowed, please create a separate build folder.")
endif ()

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

option (COMPILE_COMMANDS "cmake export compile commands" ON)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message (STATUS "Setting build type to 'Debug' as none was specified.")
	set (CMAKE_BUILD_TYPE Debug
			CACHE STRING "Choose the type of build" FORCE)

	set_property(CACHE CMAKE_BUILD_TYPE
			PROPERTY STRINGS
			"Debug"
			"Release"
			"RelWithDebInfo")
endif ()

add_subdirectory (src)

