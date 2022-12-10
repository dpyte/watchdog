############################################################
# include core
include_directories (${CMAKE_SOURCE_DIR}/core/services)
include_directories (${CMAKE_SOURCE_DIR}/core/include)

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
	nlohmann_json::nlohmann_json
)

############################################################
# add target sources
set (
	PROGRAM_SOURCES
	watchdog.cxx
)

add_executable(
	watchdog
	${PROGRAM_SOURCES}
)

target_link_libraries (
	watchdog
	PRIVATE
	${DEP_LIBRARIES}
)