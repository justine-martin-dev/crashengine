#include "CrashEngine/default-handlers/opengl/OpenGlShader.hpp"

#include <fstream>

namespace crashengine {

    OpenGlShader::OpenGlShader(const std::filesystem::path& vertexShaderPath, const std::filesystem::path& fragmentShaderPath)
    {
        this->_id = glCreateProgram();

        GLuint vertexShaderId { this->_create_shader_stage(vertexShaderPath, GL_VERTEX_SHADER) };
        GLuint fragmentShaderId { this->_create_shader_stage(fragmentShaderPath, GL_FRAGMENT_SHADER) };

        this->attach_shader(vertexShaderId);
        this->attach_shader(fragmentShaderId);

        this->link_program();

        glDeleteShader(vertexShaderId);
        glDeleteShader(fragmentShaderId);
    }

    OpenGlShader::~OpenGlShader()
    {
        glDeleteProgram(this->_id);
    }

    const ShaderVariableId OpenGlShader::get_variable_id(const std::string& variableId)
    {
        return std::make_any<GLint>(glGetUniformLocation(this->_id, variableId.c_str()));
    }

    void OpenGlShader::bind()
    {
        glUseProgram(this->_id);
    }

    void OpenGlShader::unbind()
    {
        glUseProgram(0);
    }

    void OpenGlShader::attach_shader(GLuint shaderId)
    {
        glAttachShader(this->_id, shaderId);
    }

    void OpenGlShader::link_program()
    {
        glLinkProgram(this->_id);

        GLint success = 0;
        glGetProgramiv(this->_id, GL_LINK_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(this->_id, 512, 0, infoLog);
            log::error(infoLog);
        }
    }

    GLuint OpenGlShader::_create_shader_stage(const std::filesystem::path& path, const GLenum stageType)
    {
        GLuint id { glCreateShader(stageType) };

        std::ifstream shaderFileStream { path };
        if (!shaderFileStream) {
            log::error("Couldn't find shader source '" / path / "'");
            throw std::runtime_error { { "File " / path.relative_path() / " does not exist" } };
        }

        std::stringstream source_code;
        source_code << shaderFileStream.rdbuf();
        const std::string& sourceCodeStr { source_code.str() };
        const char*        sourceCodeCStr { sourceCodeStr.c_str() };

        glShaderSource(id, 1, &sourceCodeCStr, NULL);
        glCompileShader(id);

        return id;
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 1, 1>& data)
    {
        glUniform1fv(std::any_cast<GLint>(variableId), data.count, (float*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 1, 2>& data)
    {
        glUniform2fv(std::any_cast<GLint>(variableId), data.count, (float*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 1, 3>& data)
    {
        glUniform3fv(std::any_cast<GLint>(variableId), data.count, (float*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 1, 4>& data)
    {
        glUniform4fv(std::any_cast<GLint>(variableId), data.count, (float*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::INT, 1, 1>& data)
    {
        glUniform1iv(std::any_cast<GLint>(variableId), data.count, (int*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::INT, 1, 2>& data)
    {
        glUniform1iv(std::any_cast<GLint>(variableId), data.count, (int*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::INT, 1, 3>& data)
    {
        glUniform1iv(std::any_cast<GLint>(variableId), data.count, (int*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::INT, 1, 4>& data)
    {
        glUniform1iv(std::any_cast<GLint>(variableId), data.count, (int*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::UINT, 1, 1>& data)
    {
        glUniform1uiv(std::any_cast<GLint>(variableId), data.count, (unsigned int*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::UINT, 1, 2>& data)
    {
        glUniform1uiv(std::any_cast<GLint>(variableId), data.count, (unsigned int*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::UINT, 1, 3>& data)
    {
        glUniform1uiv(std::any_cast<GLint>(variableId), data.count, (unsigned int*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::UINT, 1, 4>& data)
    {
        glUniform1uiv(std::any_cast<GLint>(variableId), data.count, (unsigned int*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 2, 2>& data)
    {
        glUniformMatrix2fv(std::any_cast<GLint>(variableId), data.count, false, (float*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 3, 3>& data)
    {
        glUniformMatrix3fv(std::any_cast<GLint>(variableId), data.count, false, (float*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 4, 4>& data)
    {
        glUniformMatrix4fv(std::any_cast<GLint>(variableId), data.count, false, (float*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 2, 3>& data)
    {
        glUniformMatrix2x3fv(std::any_cast<GLint>(variableId), data.count, false, (float*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 3, 2>& data)
    {
        glUniformMatrix3x2fv(std::any_cast<GLint>(variableId), data.count, false, (float*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 2, 4>& data)
    {
        glUniformMatrix2x4fv(std::any_cast<GLint>(variableId), data.count, false, (float*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 4, 2>& data)
    {
        glUniformMatrix4x2fv(std::any_cast<GLint>(variableId), data.count, false, (float*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 3, 4>& data)
    {
        glUniformMatrix3x4fv(std::any_cast<GLint>(variableId), data.count, false, (float*) data.data);
    }

    void OpenGlShader::update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 4, 3>& data)
    {
        glUniformMatrix4x3fv(std::any_cast<GLint>(variableId), data.count, false, (float*) data.data);
    }

}
