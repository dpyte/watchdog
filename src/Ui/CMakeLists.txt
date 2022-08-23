
include_directories (${CMAKE_SOURCE_DIR}/src/include)

set (
	UiSources
	Ui.cxx		Ui.hxx
	Window.cxx	Window.hxx
)

# === Executable ===
add_executable (WatchDogUi)
target_sources (
	WatchDogUi PRIVATE ${UiSources}
)
target_link_libraries (WatchDogUi PRIVATE glfw ${GLFW3_LIBRARY} Vulkan::Vulkan GL)

# === Library ===
add_library (WatchDogUiL)
target_sources (
	WatchDogUiL PRIVATE ${UiSources}
)
target_link_libraries (WatchDogUiL PRIVATE glfw ${GLFW3_LIBRARY} Vulkan::Vulkan GL)

