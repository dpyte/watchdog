
include_directories (${CMAKE_SOURCE_DIR}/core/services)
include_directories (${CMAKE_SOURCE_DIR}/core/include)

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
	pthread
	watchdog-core
)