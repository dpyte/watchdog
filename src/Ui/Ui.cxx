
#include "Window.hxx"

#include <stdexcept>

// Following values are of perfect fit on MBP 14" 2021
static constexpr usize height = 916;
static constexpr usize width = 1510;

void run(Ui::Window *window) {
    if (window == nullptr) return;

    const auto wwin_err = window->g_window();
    if (CheckError(wwin_err)) throw std::runtime_error(wwin_err.second);

    const auto wwindow = *wwin_err.first;
    // update the screen while we are at it

    window->update_color(Ui::WindowColor::WHITE);

    // Do not mutate this reference
    while (not window->should_close()) {
        glfwPollEvents();
    }
}

int main(int argc, const char **argv) {
    Ui::Window m_window{"WatchDog", height, width};
    run(&m_window);
}

