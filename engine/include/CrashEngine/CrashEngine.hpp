#pragma once

#include "CrashEngine/handlers/graphics_api_handler.hpp"
#include "CrashEngine/handlers/window_handler.hpp"

#include "CrashEngine/Scene.hpp"

#include <chrono>
#include <set>

namespace crashengine {
	
	class Scene;
	
	struct Color {
		int r, g, b;
	};

	struct GraphicsSettings {
		Color clearColor = {0, 0, 0};
	};

	class CrashEngine {

		private:
			Scene* scene;
		
			GraphicsApiHandler* graphicsApiHandler;
			WindowHandler* windowHandler;

			GraphicsSettings graphicsSettings;

		public:
			CrashEngine(GraphicsApiHandler* graphicsApiHandler, WindowHandler* windowHandler);
			void startGame(Scene* scene);

			GraphicsSettings& getGraphicsSettings();
			GraphicsApiHandler* getGraphicsApiHandler();
			WindowHandler* getWindowHandler();
	};

}