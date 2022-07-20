#pragma once

#include "CrashEngine/handlers/window_handler.hpp"

namespace crashengine {
	
	class CrashEngine {
		public:
			CrashEngine(WindowHandler *windowHandler);
			void startGame();

		private:
			WindowHandler* windowHandler;
	};

}