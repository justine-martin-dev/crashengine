#pragma once

#include <string>

namespace crashengine {
	struct WindowConfig {
		std::string title = "My incredible game name goes here";

		bool fullscreen = false;
		bool vsync = false;

		int foregroundFramerate = 60;
		int backgroundFramerate = 30;

		int height = 720;
		int width = 480;
	};

	class WindowHandler {
		protected:
		
		public:
			virtual void draw() = 0;

			virtual const bool isInitialized() const = 0;

			virtual void hide() = 0;
			virtual void show() = 0;
			
			virtual void pollEvents() = 0;
			virtual void waitEvents() = 0;
			virtual void swapBuffers() = 0;

			virtual void stopGame() = 0;
			virtual const bool shouldStopGame() const = 0;

			virtual void setTitle(const std::string& title) = 0;
			virtual const std::string& getTitle() const = 0;

			virtual void setHeight(const int& height) = 0;
			virtual const int getHeight() = 0;

			virtual void setWidth(const int& width) = 0;
			virtual const int getWidth() const = 0;

			virtual void setFullscreen(const bool& fullscreen) = 0;
			virtual const bool isFullscreen() const = 0;

			virtual void setVSync(const bool& vsync) = 0;
			virtual const bool getVSync() const = 0;

			virtual void setForegroundFramerate(const int& foregroundFramerate) = 0;
			virtual const int getForegroundFramerate() const = 0;

			virtual void setBackgroundFramerate(const int& backgroundFramerate) = 0;
			virtual const int getBackgroundFramerate() const = 0;
	};
}