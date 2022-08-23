
include_directories (include)

add_subdirectory (IPC)
add_subdirectory (vision)
add_subdirectory (Ui)

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

