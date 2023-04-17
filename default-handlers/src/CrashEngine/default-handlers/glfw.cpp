#include "CrashEngine/default-handlers/glfw.hpp"

namespace crashengine {

	GlfwWindowHandler::GlfwWindowHandler(const WindowConfig& config) : initialized(false), window(nullptr) {
		if(!glfwInit()) {
			log::error("Error while initializing glfw");
			return;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		this->window = glfwCreateWindow(config.width, config.height,  config.title.c_str(), glfwGetPrimaryMonitor(), nullptr);
		if(!this->window) {
			log::error("Error while creating the glfw window");
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(this->window);
		gladLoadGL(glfwGetProcAddress);

		this->title = config.title;
		this->initialized = true;
	}

	GlfwWindowHandler::~GlfwWindowHandler() {
		if(initialized) {
			glfwTerminate();
		}
	}

	const bool GlfwWindowHandler::isInitialized() const {
		return this->initialized;
	}

	void GlfwWindowHandler::hide() {
		glfwHideWindow(this->window);
	}
	
	void GlfwWindowHandler::show() {
		glfwShowWindow(this->window);
	}
	
	void GlfwWindowHandler::pollEvents() {
		glfwPollEvents();
	}
	
	void GlfwWindowHandler::waitEvents() {
		glfwWaitEvents();
	}
	
	void GlfwWindowHandler::swapBuffers() {
		glfwSwapBuffers(this->window);
	}

	void GlfwWindowHandler::stopGame() {
		glfwSetWindowShouldClose(this->window, true);
	}

	const bool GlfwWindowHandler::shouldStopGame() const {
		return glfwWindowShouldClose(this->window);
	}
	
	void GlfwWindowHandler::setTitle(const std::string& title) {
		glfwSetWindowTitle(this->window, title.c_str());
	}
	
	const std::string& GlfwWindowHandler::getTitle() const {
		return this->title;
	}

	void GlfwWindowHandler::setHeight(const int& height) {
		int w, h;
		glfwGetWindowSize(this->window, &w, &h);

		glfwSetWindowSize(this->window, w, height);
	}
	
	const int GlfwWindowHandler::getHeight() {
		int w, h;
		glfwGetWindowSize(this->window, &w, &h);

		return h;
	}
	
	void GlfwWindowHandler::setWidth(const int& width) {
		int w, h;
		glfwGetWindowSize(this->window, &w, &h);

		glfwSetWindowSize(this->window, width, h);
	}
	
	const int GlfwWindowHandler::getWidth() const {
		int w, h;
		glfwGetWindowSize(this->window, &w, &h);

		return w;
	}
	
	void GlfwWindowHandler::setFullscreen(const bool& fullscreen) {
		log::warn("Not implemented yet");
	}
	
	const bool GlfwWindowHandler::isFullscreen() const {
		log::warn("Not implemented yet");

		return false;
	}
	
	void GlfwWindowHandler::setVSync(const bool& vsync) {
		log::warn("Not implemented yet");
	}
	
	const bool GlfwWindowHandler::getVSync() const {
		log::warn("Not implemented yet");

		return false;
	}

	void GlfwWindowHandler::setForegroundFramerate(const int& foregroundFramerate) {
		log::warn("Not implemented yet");
	}
	
	const int GlfwWindowHandler::getForegroundFramerate() const {
		log::warn("Not implemented yet");

		return 0;
	}

	void GlfwWindowHandler::setBackgroundFramerate(const int& backgroundFramerate) {
		log::warn("Not implemented yet");
	}
	
	const int GlfwWindowHandler::getBackgroundFramerate() const {
		log::warn("Not implemented yet");

		return 0;
	}

}