#pragma once

#include <string>

namespace crashengine {

	struct WindowConfig {
		std::string title = "My incredible game name goes here";

		bool fullscreen = false;
		bool vsync = false;

		int foregroundFramerate = 60;
		int backgroundFramerate = 30;

		int height = 1920;
		int width = 1080;
	};

	class WindowHandler {
		protected:
		
		public:
			virtual void hide() = 0;
			virtual void show() = 0;
			
			virtual void poll_events() = 0;
			virtual void wait_events() = 0;
			virtual void swap_buffers() = 0;

			virtual void stop_game() = 0;
			virtual const bool should_close_window() const = 0;

			virtual void title(const std::string& title) = 0;
			virtual const std::string& title() const = 0;

			virtual void height(const int& height) = 0;
			virtual const int height() = 0;

			virtual void width(const int& width) = 0;
			virtual const int width() const = 0;

			virtual void is_fullscreen(const bool& fullscreen) = 0;
			virtual const bool is_fullscreen() const = 0;

			virtual void is_vsync(const bool& vsync) = 0;
			virtual const bool is_vsync() const = 0;

			virtual void foreground_framerate(const int& foregroundFramerate) = 0;
			virtual const int foreground_framerate() const = 0;

			virtual void background_framerate(const int& backgroundFramerate) = 0;
			virtual const int background_framerate() const = 0;
	};
}
