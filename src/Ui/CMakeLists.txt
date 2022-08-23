
set (
	UiSources
	Ui.cxx		Ui.hxx
	Window.cxx	Window.hxx
)

add_executable (WatchDogUi)
target_sources (
	WatchDogUi PRIVATE ${UiSources}
)

target_link_libraries (WatchDogUi PRIVATE glfw Vulkan::Vulkan)

