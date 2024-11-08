#include <CrashEngine/CrashEngine.hpp>

#include <chrono>

namespace crashengine {

	CrashEngine::CrashEngine(GraphicsApiHandler* graphicsApiHandler, WindowHandler* windowHandler) : 
		graphicsApiHandler(graphicsApiHandler), 
		windowHandler(windowHandler) {

	}

	void CrashEngine::start(Scene* scene) {
		this->scene = scene;

		windowHandler->show();
		this->scene->show();

		std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
		while(!windowHandler->shouldCloseWindow()) {
			graphicsApiHandler->clearScreen();

			windowHandler->pollEvents();

			std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
			this->scene->update(std::chrono::duration<float>(currentTime - lastTime).count());
			lastTime = currentTime;

			this->scene->draw();

			windowHandler->swapBuffers();
		}

		setScene(nullptr);
	}

	GraphicsSettings CrashEngine::getGraphicsSettings() const {
		return this->graphicsSettings;
	}

	GraphicsApiHandler* CrashEngine::getGraphicsApiHandler() const {
		return this->graphicsApiHandler;
	}

	WindowHandler* CrashEngine::getWindowHandler() const {
		return this->windowHandler;
	}

	void CrashEngine::setScene(Scene* scene) {
		if(this->scene) {
			this->scene->hide();
			delete this->scene;
		}

		this->scene = scene;
	}
}
