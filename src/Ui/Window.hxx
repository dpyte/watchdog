#ifndef WATCHDOGUI_WINDOW_HXX
#define WATCHDOGUI_WINDOW_HXX

#define GLFW_INCLUDE_VULKAN 
#include <GLFW/glfw3.h>

namespace Ui {
	class Window {
	private:
		GLFWwindow *window;
	};
}

#endif // WATCHDOGUI_WINDOW_HXX
