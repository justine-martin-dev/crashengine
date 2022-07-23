#pragma once

#include "handlers-interfaces/window_handler.hpp"

namespace crashengine {
	
	class CrashEngine {
		public:
			CrashEngine(WindowHandler *windowHandler);
			void startGame();

		private:
			WindowHandler* windowHandler;
	};

}
