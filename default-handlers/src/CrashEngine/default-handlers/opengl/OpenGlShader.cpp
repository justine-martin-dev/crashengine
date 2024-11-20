#include "CrashEngine/default-handlers/opengl/OpenGlShader.hpp"

namespace crashengine {

    OpenGlShader::OpenGlShader()
    {
        this->id = glCreateProgram();
    }

    OpenGlShader::~OpenGlShader()
    {
        glDeleteProgram(this->id);
    }

    const ShaderVariableId OpenGlShader::getVariableId(const std::string& variable_id)
    {
        return std::make_any<GLint>(glGetUniformLocation(this->id, variable_id.c_str()));
    }

    void OpenGlShader::bind()
    {
        glUseProgram(this->id);
    }

    void OpenGlShader::unbind()
    {
        glUseProgram(0);
    }

    void OpenGlShader::attachShader(GLuint shaderId)
    {
        glAttachShader(this->id, shaderId);
    }

    void OpenGlShader::linkProgram()
    {
        glLinkProgram(this->id);

        GLint success = 0;
        glGetProgramiv(this->id, GL_LINK_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(this->id, 512, 0, infoLog);
            log::error(infoLog);
        }
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 1, 1>& data)
    {
        glUniform1fv(std::any_cast<GLint>(variable_id), data.count, (float*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 1, 2>& data)
    {
        glUniform2fv(std::any_cast<GLint>(variable_id), data.count, (float*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 1, 3>& data)
    {
        glUniform3fv(std::any_cast<GLint>(variable_id), data.count, (float*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 1, 4>& data)
    {
        glUniform4fv(std::any_cast<GLint>(variable_id), data.count, (float*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::INT, 1, 1>& data)
    {
        glUniform1iv(std::any_cast<GLint>(variable_id), data.count, (int*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::INT, 1, 2>& data)
    {
        glUniform1iv(std::any_cast<GLint>(variable_id), data.count, (int*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::INT, 1, 3>& data)
    {
        glUniform1iv(std::any_cast<GLint>(variable_id), data.count, (int*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::INT, 1, 4>& data)
    {
        glUniform1iv(std::any_cast<GLint>(variable_id), data.count, (int*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::UINT, 1, 1>& data)
    {
        glUniform1uiv(std::any_cast<GLint>(variable_id), data.count, (unsigned int*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::UINT, 1, 2>& data)
    {
        glUniform1uiv(std::any_cast<GLint>(variable_id), data.count, (unsigned int*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::UINT, 1, 3>& data)
    {
        glUniform1uiv(std::any_cast<GLint>(variable_id), data.count, (unsigned int*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::UINT, 1, 4>& data)
    {
        glUniform1uiv(std::any_cast<GLint>(variable_id), data.count, (unsigned int*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 2, 2>& data)
    {
        glUniformMatrix2fv(std::any_cast<GLint>(variable_id), data.count, false, (float*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 3, 3>& data)
    {
        glUniformMatrix3fv(std::any_cast<GLint>(variable_id), data.count, false, (float*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 4, 4>& data)
    {
        glUniformMatrix4fv(std::any_cast<GLint>(variable_id), data.count, false, (float*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 2, 3>& data)
    {
        glUniformMatrix2x3fv(std::any_cast<GLint>(variable_id), data.count, false, (float*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 3, 2>& data)
    {
        glUniformMatrix3x2fv(std::any_cast<GLint>(variable_id), data.count, false, (float*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 2, 4>& data)
    {
        glUniformMatrix2x4fv(std::any_cast<GLint>(variable_id), data.count, false, (float*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 4, 2>& data)
    {
        glUniformMatrix4x2fv(std::any_cast<GLint>(variable_id), data.count, false, (float*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 3, 4>& data)
    {
        glUniformMatrix3x4fv(std::any_cast<GLint>(variable_id), data.count, false, (float*) data.data);
    }

    void OpenGlShader::updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 4, 3>& data)
    {
        glUniformMatrix4x3fv(std::any_cast<GLint>(variable_id), data.count, false, (float*) data.data);
    }

}
