#pragma once

#include "CrashEngine/handlers/graphics_api_handler.hpp"
#include "CrashEngine/handlers/window_handler.hpp"

#include "CrashEngine/Scene.hpp"

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
			void start(Scene* scene);

			GraphicsSettings getGraphicsSettings() const;
			GraphicsApiHandler* getGraphicsApiHandler() const;
			WindowHandler* getWindowHandler() const;

			void setScene(Scene* scene);
	};

}
