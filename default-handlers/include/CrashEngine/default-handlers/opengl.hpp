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

			void clear_screen() override;

			void render() override;

			Shader* create_shader(const std::filesystem::path& vertexShaderPath, const std::filesystem::path& fragmentShaderPath) override;
			Mesh* create_mesh(std::vector<float>& vertices, std::vector<float>& verticesNormals, std::vector<float>& textureCoordinates, std::vector<unsigned int>& verticesIndex) override;
			Texture* create_texture(const std::string& path) override;
			Texture* create_texture(const std::string& path, TextureSettings settings) override;
	};
}
