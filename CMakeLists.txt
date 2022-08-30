cmake_minimum_required (VERSION 3.12)

set_property (GLOBAL PROPERTY USE_FOLDERS ON)

project (
	WatchDog
	CXX
)

if (${CMAKE_SOURCE_DIR} STREQUAL {CMAKE_BINARY_DIR})
	message (FATAL_ERROR "In-source build is not allowed, please create a separate build folder.")
endif ()

if (NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
	message (FATAL_ERROR "Cannot compile this project on 32-bit architecture")
endif()

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

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

# Set external projects
set (ExternalPathToTinyXML2 "${CMAKE_CURRENT_SOURCE_DIR}/external/tinyxml2" CACHE STRING "Path to tinyxml2 conforms to")
add_subdirectory ("${ExternalPathToTinyXML2}")

add_subdirectory (src)

# Testing
include (FetchContent)
FetchContent_Declare (
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)
enable_testing ()
add_subdirectory (test)


