#include "CrashEngine/default-handlers/opengl/OpenGlShader.hpp"

#include <iostream>

namespace crashengine {
	
	OpenGlShader::OpenGlShader() {
		this->id = glCreateProgram();
	}

	OpenGlShader::~OpenGlShader() {
		glDeleteProgram(this->id);
	}
	
	void OpenGlShader::registerVariables(const std::string& variables...)  {
		registerVariable(variables);
	}

	void OpenGlShader::registerVariable(const std::string& variable)  {
		this->variableLocations[variable] = glGetUniformLocation(this->id, variable.c_str());
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
			log::error(infoLog);
		}
	}

	void OpenGlShader::updateVec1fVar(const std::string& variable, const Data<DataType::FLOAT, 1, 1>& data) {
		glUniform1fv(this->variableLocations[variable], data.count, (float*) data.data);
	}

	void OpenGlShader::updateVec2fVar(const std::string& variable, const Data<DataType::FLOAT, 1, 2>& data) {
		glUniform2fv(this->variableLocations[variable], data.count, (float*) data.data);
	}

	void OpenGlShader::updateVec3fVar(const std::string& variable, const Data<DataType::FLOAT, 1, 3>& data) {
		glUniform3fv(this->variableLocations[variable], data.count, (float*) data.data);
	}

	void OpenGlShader::updateVec4fVar(const std::string& variable, const Data<DataType::FLOAT, 1, 4>& data) {
		glUniform4fv(this->variableLocations[variable], data.count, (float*) data.data);
	}

	void OpenGlShader::updateVec1iVar(const std::string& variable, const Data<DataType::INT, 1, 1>& data) {
		glUniform1iv(this->variableLocations[variable], data.count, (int*) data.data);
	}

	void OpenGlShader::updateVec2iVar(const std::string& variable, const Data<DataType::INT, 1, 2>& data) {
		glUniform1iv(this->variableLocations[variable], data.count, (int*) data.data);
	}

	void OpenGlShader::updateVec3iVar(const std::string& variable, const Data<DataType::INT, 1, 3>& data) {
		glUniform1iv(this->variableLocations[variable], data.count, (int*) data.data);
	}

	void OpenGlShader::updateVec4iVar(const std::string& variable, const Data<DataType::INT, 1, 4>& data) {
		glUniform1iv(this->variableLocations[variable], data.count, (int*) data.data);
	}

	void OpenGlShader::updateVec1uiVar(const std::string& variable, const Data<DataType::UINT, 1, 1>& data) {
		glUniform1uiv(this->variableLocations[variable], data.count, (unsigned int*) data.data);
	}

	void OpenGlShader::updateVec2uiVar(const std::string& variable, const Data<DataType::UINT, 1, 2>& data) {
		glUniform1uiv(this->variableLocations[variable], data.count, (unsigned int*) data.data);
	}

	void OpenGlShader::updateVec3uiVar(const std::string& variable, const Data<DataType::UINT, 1, 3>& data) {
		glUniform1uiv(this->variableLocations[variable], data.count, (unsigned int*) data.data);
	}

	void OpenGlShader::updateVec4uiVar(const std::string& variable, const Data<DataType::UINT, 1, 4>& data) {
		glUniform1uiv(this->variableLocations[variable], data.count, (unsigned int*) data.data);
	}

	void OpenGlShader::updateMatrix2Var(const std::string& variable, const Data<DataType::FLOAT, 2, 2>& data) {
		glUniformMatrix2fv(this->variableLocations[variable], data.count, false, (float*) data.data);
	}

	void OpenGlShader::updateMatrix3Var(const std::string& variable, const Data<DataType::FLOAT, 3, 3>& data) {
		glUniformMatrix3fv(this->variableLocations[variable], data.count, false, (float*) data.data);
	}

	void OpenGlShader::updateMatrix4Var(const std::string& variable, const Data<DataType::FLOAT, 4, 4>& data) {
		glUniformMatrix4fv(this->variableLocations[variable], data.count, false, (float*) data.data);
	}

	void OpenGlShader::updateMatrix2x3Var(const std::string& variable, const Data<DataType::FLOAT, 2, 3>& data) {
		glUniformMatrix2x3fv(this->variableLocations[variable], data.count, false, (float*) data.data);
	}

	void OpenGlShader::updateMatrix3x2Var(const std::string& variable, const Data<DataType::FLOAT, 3, 2>& data) {
		glUniformMatrix3x2fv(this->variableLocations[variable], data.count, false, (float*) data.data);
	}

	void OpenGlShader::updateMatrix2x4Var(const std::string& variable, const Data<DataType::FLOAT, 2, 4>& data) {
		glUniformMatrix2x4fv(this->variableLocations[variable], data.count, false, (float*) data.data);
	}

	void OpenGlShader::updateMatrix4x2Var(const std::string& variable, const Data<DataType::FLOAT, 4, 2>& data) {
		glUniformMatrix4x2fv(this->variableLocations[variable], data.count, false, (float*) data.data);
	}

	void OpenGlShader::updateMatrix3x4Var(const std::string& variable, const Data<DataType::FLOAT, 3, 4>& data) {
		glUniformMatrix3x4fv(this->variableLocations[variable], data.count, false, (float*) data.data);
	}

	void OpenGlShader::updateMatrix4x3Var(const std::string& variable, const Data<DataType::FLOAT, 4, 3>& data) {
		glUniformMatrix4x3fv(this->variableLocations[variable], data.count, false, (float*) data.data);
	}

} 
