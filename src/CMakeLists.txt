
include_directories (include)

# add_subdirectory (WatchDogApp)
add_subdirectory (IPC)
add_subdirectory (vision)

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
	IpcServer
)

