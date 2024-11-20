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
			Scene* _scene;
		
			GraphicsApiHandler* _graphicsApiHandler;
			WindowHandler* _windowHandler;

			GraphicsSettings _graphicsSettings;

		public:
			CrashEngine(GraphicsApiHandler* graphicsApiHandler, WindowHandler* windowHandler);
			void start(Scene* scene);

			GraphicsSettings graphics_settings() const;
			GraphicsApiHandler* graphics_api_handler() const;
			WindowHandler* window_handler() const;

			void scene(Scene* scene);
	};

}
