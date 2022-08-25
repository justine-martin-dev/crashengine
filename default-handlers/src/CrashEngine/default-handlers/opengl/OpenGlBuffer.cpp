#include "CrashEngine/default-handlers/opengl/OpenGlBuffer.hpp"

#include <iostream>

namespace crashengine {

	template <typename T>
	OpenGlBuffer<T>::OpenGlBuffer(GLenum target) : target(target) {
		glGenBuffers(1, &this->id);
	}

	template <typename T>
	OpenGlBuffer<T>::~OpenGlBuffer() {
		glDeleteBuffers(1, &this->id);
	}

	template <typename T>
	void OpenGlBuffer<T>::bind() {
		glBindBuffer(this->target, this->id);
	}

	template <typename T>
	void OpenGlBuffer<T>::unbind() {
		glBindBuffer(this->target, 0);
	}

	template <typename T>
	void OpenGlBuffer<T>::setData(std::vector<T>& data) {
		glBufferData(this->target, sizeof(T)*data.size(), data.data(), GL_STATIC_DRAW);
	}

}