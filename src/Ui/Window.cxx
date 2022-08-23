
#include <utility>

#include "Window.hxx"

Ui::Window::Window(String win_name, usize ht, usize wd)
    : window_name(std::move(win_name)), height(ht), width(wd) {
    // OpenGL is deprecated on macOS and hence this prechecks are required
    if (not glfwVulkanSupported()) {
        std::fprintf(stderr, "Vulkan api not found for current operating system\n");
        // TODO: Report to the global messaging system
    }

    init_window();
    // glClearColor(1, 1, 1, 0);
}

Ui::Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Ui::Window::init_window() {
    const auto ginit_stat = glfwInit();
    if (not ginit_stat) return;  // Report to the user

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), window_name.c_str(),
                      glfwGetPrimaryMonitor(), nullptr);
    if (not window) { glfwTerminate(); /* Report to the user */ }
}

Result<GLFWwindow*> Ui::Window::g_window() const {
    if (window == nullptr) {
        return ReturnResult(nullptr, "[1] Result is no longer active. [2] Failed to initialize the window");
    }
    return ReturnResult(window, String{});
}

void Ui::Window::update_color(Ui::WindowColor color) {
    glfwMakeContextCurrent(window);
    switch (color) {
        case WindowColor::RED:
            glClearColor(0.8, 0, 0, 1);
            break;
        case WindowColor::GREEN:
            glClearColor(0, 0.8, 0, 1);
            break;
        case WindowColor::BLUE:
            glClearColor(0, 0, 0.8, 1);
            break;
        case WindowColor::WHITE:
        default:
            glClearColor(1, 1, 1, 1);
            break;
    }
    glClear(GL_COLOR_BUFFER_BIT);
}
