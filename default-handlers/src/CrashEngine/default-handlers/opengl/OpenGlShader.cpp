#include "CrashEngine/default-handlers/opengl/OpenGlShader.hpp"

#include <iostream>

namespace crashengine {
	
	OpenGlShader::OpenGlShader() {
		this->id = glCreateProgram();
	}

	OpenGlShader::~OpenGlShader() {
		glDeleteProgram(this->id);
	}

	void OpenGlShader::bind() {
		glUseProgram(this->id);
	}

	void OpenGlShader::unbind() {
		glUseProgram(0);
	}

	void OpenGlShader::attachShader(GLuint shaderId) {
		glAttachShader(this->id, shaderId);
	}

	void OpenGlShader::linkProgram() {
		glLinkProgram(this->id);

		GLint success = 0;
		glGetProgramiv(this->id, GL_LINK_STATUS, &success);
		if(!success) {
			char infoLog[512];
			glGetProgramInfoLog(this->id, 512, 0, infoLog);
			std::cout << infoLog << std::endl;
		}
	}

} 
