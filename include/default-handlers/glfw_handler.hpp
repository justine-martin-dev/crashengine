#pragma once

#include "handlers-interfaces/window_handler.hpp"

#include "glad/gl.h"
#include "GLFW/glfw3.h"

#include <string>

namespace crashengine {

	class GlfwWindowHandler : public WindowHandler {
		private:
			GLFWwindow *window;
			std::string title;

			bool initialized;

		public:
			GlfwWindowHandler(const WindowConfig& config);
			~GlfwWindowHandler();

			void draw() override;

			const bool isInitialized() const override;

			void hide() override;
			void show() override;
			
			void pollEvents() override;
			void waitEvents() override;
			void swapBuffers() override;

			void stopGame() override;
			const bool shouldStopGame() const override;

			void setTitle(const std::string& title) override;
			const std::string& getTitle() const override;

			void setHeight(const int& height) override;
			const int getHeight() override;

			void setWidth(const int& width) override;
			const int getWidth() const override;

			void setFullscreen(const bool& fullscreen) override;
			const bool isFullscreen() const override;

			void setVSync(const bool& vsync) override;
			const bool getVSync() const override;

			void setForegroundFramerate(const int& foregroundFramerate) override;
			const int getForegroundFramerate() const override;

			void setBackgroundFramerate(const int& backgroundFramerate) override;
			const int getBackgroundFramerate() const override;
	};
}
