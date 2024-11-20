#include "CrashEngine/default-handlers/glfw.hpp"

#include "CrashEngine/logger.hpp"
#include <stdexcept>

namespace crashengine {

    GlfwWindowHandler::GlfwWindowHandler(const WindowConfig& config)
        : _window(nullptr)
    {
        if (!glfwInit()) {
            throw std::runtime_error("Error while initializing glfw");
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        this->_window = glfwCreateWindow(config.width, config.height, config.title.c_str(), glfwGetPrimaryMonitor(), nullptr);
        if (!this->_window) {
            glfwTerminate();
            throw std::runtime_error("Error while creating the glfw window");
            return;
        }

        glfwMakeContextCurrent(this->_window);
        gladLoadGL(glfwGetProcAddress);

        this->_title = config.title;
    }

    GlfwWindowHandler::~GlfwWindowHandler()
    {
        if (this->_window) {
            glfwDestroyWindow(this->_window);
            glfwTerminate();
        }
    }

    void GlfwWindowHandler::hide()
    {
        glfwHideWindow(this->_window);
    }

    void GlfwWindowHandler::show()
    {
        glfwShowWindow(this->_window);
    }

    void GlfwWindowHandler::poll_events()
    {
        glfwPollEvents();
    }

    void GlfwWindowHandler::wait_events()
    {
        glfwWaitEvents();
    }

    void GlfwWindowHandler::swap_buffers()
    {
        glfwSwapBuffers(this->_window);
    }

    void GlfwWindowHandler::stop_game()
    {
        glfwSetWindowShouldClose(this->_window, true);
    }

    const bool GlfwWindowHandler::should_close_window() const
    {
        return glfwWindowShouldClose(this->_window);
    }

    void GlfwWindowHandler::title(const std::string& title)
    {
        glfwSetWindowTitle(this->_window, title.c_str());
    }

    const std::string& GlfwWindowHandler::title() const
    {
        return this->_title;
    }

    void GlfwWindowHandler::height(const int& height)
    {
        int w, h;
        glfwGetWindowSize(this->_window, &w, &h);

        glfwSetWindowSize(this->_window, w, height);
    }

    const int GlfwWindowHandler::height()
    {
        int w, h;
        glfwGetWindowSize(this->_window, &w, &h);

        return h;
    }

    void GlfwWindowHandler::width(const int& width)
    {
        int w, h;
        glfwGetWindowSize(this->_window, &w, &h);

        glfwSetWindowSize(this->_window, width, h);
    }

    const int GlfwWindowHandler::width() const
    {
        int w, h;
        glfwGetWindowSize(this->_window, &w, &h);

        return w;
    }

    void GlfwWindowHandler::is_fullscreen(const bool& fullscreen)
    {
        log::warn("Not implemented yet");
    }

    const bool GlfwWindowHandler::is_fullscreen() const
    {
        log::warn("Not implemented yet");

        return false;
    }

    void GlfwWindowHandler::is_vsync(const bool& vsync)
    {
        log::warn("Not implemented yet");
    }

    const bool GlfwWindowHandler::is_vsync() const
    {
        log::warn("Not implemented yet");

        return false;
    }

    void GlfwWindowHandler::foreground_framerate(const int& foregroundFramerate)
    {
        log::warn("Not implemented yet");
    }

    const int GlfwWindowHandler::foreground_framerate() const
    {
        log::warn("Not implemented yet");

        return 0;
    }

    void GlfwWindowHandler::background_framerate(const int& backgroundFramerate)
    {
        log::warn("Not implemented yet");
    }

    const int GlfwWindowHandler::background_framerate() const
    {
        log::warn("Not implemented yet");

        return 0;
    }

}
