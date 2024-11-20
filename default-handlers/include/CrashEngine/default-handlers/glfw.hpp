#pragma once

#include "CrashEngine/handlers/window_handler.hpp"

#include "glad/gl.h"
#include "GLFW/glfw3.h"

#include <string>

namespace crashengine {

	class GlfwWindowHandler : public WindowHandler {
		private:
			GLFWwindow *_window;
			std::string _title;

		public:
			GlfwWindowHandler(const WindowConfig& config);
			~GlfwWindowHandler();

			void hide() override;
			void show() override;
			
			void poll_events() override;
			void wait_events() override;
			void swap_buffers() override;

			void stop_game() override;
			const bool should_close_window() const override;

			void title(const std::string& title) override;
			const std::string& title() const override;

			void height(const int& height) override;
			const int height() override;

			void width(const int& width) override;
			const int width() const override;

			void is_fullscreen(const bool& fullscreen) override;
			const bool is_fullscreen() const override;

			void is_vsync(const bool& vsync) override;
			const bool is_vsync() const override;

			void foreground_framerate(const int& foregroundFramerate) override;
			const int foreground_framerate() const override;

			void background_framerate(const int& backgroundFramerate) override;
			const int background_framerate() const override;
	};
}
