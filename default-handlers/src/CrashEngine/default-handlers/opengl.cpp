#include "CrashEngine/default-handlers/opengl.hpp"

#include "CrashEngine/default-handlers/opengl/OpenGlMesh.hpp"
#include "CrashEngine/default-handlers/opengl/OpenGlShader.hpp"
#include "CrashEngine/default-handlers/opengl/OpenGlTexture.hpp"
#include "CrashEngine/logger.hpp"

#include <fstream>
#include <stdexcept>

namespace crashengine {

    void OpenGlGraphicsApiHandler::clearScreen()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 0, 0, 1);
    }

    void OpenGlGraphicsApiHandler::render()
    {
        log::warn("Not implemented yet");
    }

    Shader* OpenGlGraphicsApiHandler::createShader(const std::filesystem::path& vertex_shader_path, const std::filesystem::path& fragment_shader_path)
    {
        OpenGlShader* shader = new OpenGlShader();

        GLuint vertex_shader_id { createShaderStage(vertex_shader_path, GL_VERTEX_SHADER) };
        GLuint fragment_shader_id { createShaderStage(fragment_shader_path, GL_FRAGMENT_SHADER) };

        shader->attachShader(vertex_shader_id);
        shader->attachShader(fragment_shader_id);

        shader->linkProgram();

        glDeleteShader(vertex_shader_id);
        glDeleteShader(fragment_shader_id);

        return shader;
    }

    GLuint OpenGlGraphicsApiHandler::createShaderStage(const std::filesystem::path& path, const GLenum stage_type)
    {
        GLuint id { glCreateShader(stage_type) };

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

    Mesh* OpenGlGraphicsApiHandler::createMesh(std::vector<float>& vertices, std::vector<float>& verticesNormals, std::vector<float>& textureCoordinates, std::vector<unsigned int>& verticesIndex)
    {
        return new OpenGlMesh(vertices, verticesNormals, textureCoordinates, verticesIndex);
    }

    Texture* OpenGlGraphicsApiHandler::createTexture(const std::string& path)
    {
        TextureSettings settings;
        return this->createTexture(path, settings);
    }

    Texture* OpenGlGraphicsApiHandler::createTexture(const std::string& path, TextureSettings settings)
    {
        return new OpenGlTexture(path, settings);
    }

}
