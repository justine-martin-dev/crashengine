#include "MainScene.hpp"

#include "CrashEngine/CrashEngine.hpp"

#include "CrashEngine/default-handlers/glfw.hpp"
#include "CrashEngine/default-handlers/opengl.hpp"

#include <iostream>

int main(int argc, char **argv) {
	crashengine::WindowConfig config;
	config.width = 2560;
	config.height = 1440;

	try {
		crashengine::GlfwWindowHandler windowHandler {config};
		crashengine::OpenGlGraphicsApiHandler openglGraphicsApiHandler;

		crashengine::CrashEngine engine(&openglGraphicsApiHandler, &windowHandler);
		engine.start(new MainScene(&engine));
	} catch(std::runtime_error &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}
