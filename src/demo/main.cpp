#include "crashengine.hpp"
#include "glfw_handler.hpp"

#include <iostream>

int main(int argc, char **argv) {
	crashengine::WindowConfig config;
	config.width = 2560;
	config.height = 1440;
	crashengine::GlfwWindowHandler windowHandler(config);
	if(!windowHandler.isInitialized()) {
		std::cout << "Hé bah non trou du cul !" << std::endl;
	}

	crashengine::CrashEngine engine(&windowHandler);
	engine.startGame();
	
	return 0;
}
