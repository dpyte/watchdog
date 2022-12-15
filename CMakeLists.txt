cmake_minimum_required (VERSION 3.21)

set_property (GLOBAL PROPERTY USE_FOLDERS ON)

project (
	WatchDog
	C
	CXX
)

if (${CMAKE_SOURCE_DIR} STREQUAL {CMAKE_BINARY_DIR})
	message (FATAL_ERROR "In-source build is not allowed, please create a separate build folder.")
endif ()

if (NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
	message (FATAL_ERROR "Cannot compile this project on 32-bit architecture")
endif()

set (CMAKE_CXX_STANDARD 20)
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
############################################################
## detect includes
include (cmake/CheckIncludes.cmake)

## print info
message (STATUS "build info:")
message (STATUS "  Host System: ${CMAKE_HOST_SYSTEM}")
message (STATUS "  Host System Name: ${CMAKE_HOST_SYSTEM_NAME}")
message (STATUS "  Host System Processor: ${CMAKE_HOST_SYSTEM_PROCESSOR}")

include (FetchContent)
include (CheckCXXCompilerFlag)

############################################################
# Set compiler flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fstack-protector-strong -funroll-loops -Wconversion")

check_cxx_compiler_flag (-fno-builtin HAVE_FNO_BUILTIN)
check_cxx_compiler_flag (-fstack-protector-strong HAS_STACK_PROTECTOR_STRONG)

if (HAVE_FNO_BUILTIN)
	add_compile_options (-fno-builtin)
endif ()

if (HAS_STACK_PROTECTOR_STRONG)
	add_compile_options (-fstack-protector-strong)
	link_libraries (-fstack-protector-strong)
endif ()

add_compile_options (-Wstrict-overflow=2)

# Configure output directory
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

############################################################
# Common dependency
set (
	DEP_LIBRARIES
	watchdog-core
	pthread
	rt
	spdlog
	fmt
	dl
	ssl
	crypto
	sqlite3
	SQLiteCpp
	nlohmann_json::nlohmann_json
)

############################################################
# core
add_subdirectory (core)

############################################################
# src

add_subdirectory (src)

add_dependencies (watchdog watchdog-core)