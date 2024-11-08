#pragma once

#include "CrashEngine/CrashEngine.hpp"

namespace crashengine {

	class CrashEngine;

	class Scene {

		protected:

			CrashEngine* engine; 

		public:

			Scene(CrashEngine* engine);
			virtual ~Scene() = default;

			virtual void show() = 0;
			virtual void hide() = 0;

			virtual void resized(int width, int height) = 0;

			virtual void update(float delta) = 0;
			virtual void draw() = 0;
	};

}
