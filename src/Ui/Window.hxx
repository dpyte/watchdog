#ifndef WATCHDOGUI_WINDOW_HXX
#define WATCHDOGUI_WINDOW_HXX

#include "Result.hxx"
#include "WdTypes.hxx"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Ui {

    enum class WindowColor {
        RED,
        BLUE,
        GREEN,
        WHITE
    };

	class Window {
    private:
        template <typename Type>
        struct WinError : WdResult::Err {
            Result<Type> result;
            explicit WinError(String message) : WdResult::Err(message) {}
        };

    private:
		String window_name;
        usize height;
        usize width;
        GLFWwindow *window;

    public:
        Window() = delete;

        /**
         * Initialize a window instance
         * @param win_name Name of the window (shown in title bar)
         * @param ht Window's height
         * @param wd Window's width
         */
        explicit Window(String win_name, usize ht, usize wd);
        ~Window();

        /**
         * Initialize the window
         */
        void init_window();

        /**
         * Query whether the user has closed the window or not
         * @return whether the window is still up and running
         */
        [[nodiscard]] inline bool should_close() { return glfwWindowShouldClose(window); }

        /**
         * Return working window
         * @return Returns current window context
         */
         [[nodiscard]] Result<GLFWwindow*> g_window() const;

         /**
          * Updates window background for given context to the color provided from the limited set of colors
          * @param color object of type WindowColor
          */
         void update_color(WindowColor color);
    };
}

#endif // WATCHDOGUI_WINDOW_HXX
