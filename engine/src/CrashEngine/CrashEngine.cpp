#include <CrashEngine/CrashEngine.hpp>

namespace crashengine {

	CrashEngine::CrashEngine(GraphicsApiHandler* graphicsApiHandler, WindowHandler* windowHandler) : graphicsApiHandler(graphicsApiHandler), windowHandler(windowHandler) {

	}

	void CrashEngine::startGame(Scene* scene) {
		this->scene = scene;

		windowHandler->show();
		this->scene->show();

		std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
		while(!windowHandler->shouldStopGame()) {
			graphicsApiHandler->clearScreen();

			std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();

			this->scene->update(std::chrono::duration<float>(currentTime - lastTime).count());
			lastTime = currentTime;

			this->scene->draw();

			windowHandler->swapBuffers();
			windowHandler->pollEvents();
		}

		this->scene->hide();
	}

	GraphicsSettings& CrashEngine::getGraphicsSettings() {
		return this->graphicsSettings;
	}

	GraphicsApiHandler* CrashEngine::getGraphicsApiHandler() {
		return this->graphicsApiHandler;
	}

	WindowHandler* CrashEngine::getWindowHandler() {
		return this->windowHandler;
	}
}