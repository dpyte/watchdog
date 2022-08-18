
include_directories (${CMAKE_SOURCE_DIR}/src/include)

set (
	IpcSources
	IpcChannel.cxx  IpcChannel.hxx
)

add_library (
	IpcServer
	${IpcSources}
)
