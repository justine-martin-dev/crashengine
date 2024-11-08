#pragma once

#include "CrashEngine/Mesh.hpp"
#include "CrashEngine/Shader.hpp"
#include "CrashEngine/Texture.hpp"
#include "CrashEngine/handlers/graphics_api_handler.hpp"

#include "glad/gl.h"

#include <filesystem>

namespace crashengine {
	
	class OpenGlGraphicsApiHandler : public GraphicsApiHandler {
		protected:
		
		public:

			void clearScreen() override;

			void render() override;

			Shader* createShader(const std::filesystem::path& vertex_shader_path, const std::filesystem::path& fragment_shader_path) override;
			GLuint createShaderStage(const std::filesystem::path& path, const GLenum stage_type);
			Mesh* createMesh(std::vector<float>& vertices, std::vector<float>& verticesNormals, std::vector<float>& textureCoordinates, std::vector<unsigned int>& verticesIndex) override;
			Texture* createTexture(const std::string& path) override;
			Texture* createTexture(const std::string& path, TextureSettings settings) override;
	};
}
