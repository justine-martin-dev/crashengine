#include "MainScene.hpp"

#include "CrashEngine/CrashEngine.hpp"

#include "CrashEngine/default-handlers/glfw.hpp"
#include "CrashEngine/default-handlers/opengl.hpp"

#include <iostream>

int main(int argc, char **argv) {
	crashengine::WindowConfig config;
	config.width = 2560;
	config.height = 1440;

	crashengine::GlfwWindowHandler *windowHandler = new crashengine::GlfwWindowHandler(config);
	if(!windowHandler->isInitialized()) {
		std::cout << "Error while initializing GLFW handler" << std::endl;
		return 1;
	}

	crashengine::OpenGlGraphicsApiHandler* openglGraphicsApiHandler = new crashengine::OpenGlGraphicsApiHandler();

	crashengine::CrashEngine engine(openglGraphicsApiHandler, windowHandler);
	engine.startGame(new MainScene(&engine));
	
	return 0;
}
