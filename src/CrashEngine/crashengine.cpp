#include "crashengine.hpp"

namespace crashengine {
	CrashEngine::CrashEngine(WindowHandler* windowHandler) : windowHandler(windowHandler) {

	}

	void CrashEngine::startGame() {
		windowHandler->show();
		while(!windowHandler->shouldStopGame()) {
			windowHandler->draw();

			windowHandler->swapBuffers();
			windowHandler->pollEvents();
		}
	}
}
