
include_directories ("${CMAKE_SOURCE_DIR}/src/include")

set (CamSources
		Xml.cxx Xml.hxx
	)

add_library (
	WdCamera
	${CamSources}
)

target_link_libraries (
	WdCamera
	tinyxml2::tinyxml2
)
