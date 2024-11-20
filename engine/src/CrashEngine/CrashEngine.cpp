#include <CrashEngine/CrashEngine.hpp>

#include <chrono>

namespace crashengine {

    CrashEngine::CrashEngine(GraphicsApiHandler* graphicsApiHandler, WindowHandler* windowHandler)
        : _graphicsApiHandler(graphicsApiHandler)
        , _windowHandler(windowHandler)
    {
    }

    void CrashEngine::start(Scene* scene)
    {
        this->_scene = scene;

        this->_windowHandler->show();
        this->_scene->show();

        std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
        while (!this->_windowHandler->should_close_window()) {
            this->_graphicsApiHandler->clear_screen();

            this->_windowHandler->poll_events();

            std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
            this->_scene->update(std::chrono::duration<float>(currentTime - lastTime).count());
            lastTime = currentTime;

            this->_scene->draw();

            this->_windowHandler->swap_buffers();
        }

        this->scene(nullptr);
    }

    GraphicsSettings CrashEngine::graphics_settings() const
    {
        return this->_graphicsSettings;
    }

    GraphicsApiHandler* CrashEngine::graphics_api_handler() const
    {
        return this->_graphicsApiHandler;
    }

    WindowHandler* CrashEngine::window_handler() const
    {
        return this->_windowHandler;
    }

    void CrashEngine::scene(Scene* scene)
    {
        if (this->_scene) {
            this->_scene->hide();
            delete this->_scene;
        }

        this->_scene = scene;
    }
}
