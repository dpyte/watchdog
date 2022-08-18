
include_directories ("${CMAKE_SOURCE_DIR}/src/include")

set (CamSources
	Data.cxx            Data.hxx
	)

add_library (
	Camera
	${CamSources}
)
