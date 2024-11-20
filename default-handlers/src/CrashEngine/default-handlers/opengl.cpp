#include "CrashEngine/default-handlers/opengl.hpp"

#include "CrashEngine/default-handlers/opengl/OpenGlMesh.hpp"
#include "CrashEngine/default-handlers/opengl/OpenGlShader.hpp"
#include "CrashEngine/default-handlers/opengl/OpenGlTexture.hpp"
#include "CrashEngine/logger.hpp"

#include <fstream>
#include <stdexcept>

namespace crashengine {

    void OpenGlGraphicsApiHandler::clear_screen()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 0, 0, 1);
    }

    void OpenGlGraphicsApiHandler::render()
    {
        log::warn("Not implemented yet");
    }

    Shader* OpenGlGraphicsApiHandler::create_shader(const std::filesystem::path& vertexShaderPath, const std::filesystem::path& fragmentShaderPath)
    {
        OpenGlShader* shader = new OpenGlShader(vertexShaderPath, fragmentShaderPath);

        return shader;
    }

    Mesh* OpenGlGraphicsApiHandler::create_mesh(std::vector<float>& vertices, std::vector<float>& verticesNormals, std::vector<float>& textureCoordinates, std::vector<unsigned int>& verticesIndex)
    {
        return new OpenGlMesh(vertices, verticesNormals, textureCoordinates, verticesIndex);
    }

    Texture* OpenGlGraphicsApiHandler::create_texture(const std::string& path)
    {
        TextureSettings settings;
        return this->create_texture(path, settings);
    }

    Texture* OpenGlGraphicsApiHandler::create_texture(const std::string& path, TextureSettings settings)
    {
        return new OpenGlTexture(path, settings);
    }

}
