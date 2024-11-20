#pragma once

#include "CrashEngine/Mesh.hpp"
#include "CrashEngine/Shader.hpp"
#include "CrashEngine/Texture.hpp"

#include <filesystem>
#include <string>
#include <vector>

namespace crashengine {

	enum ShaderType {
		VERTEX, GEOMETRY, FRAGMENT
	};

	class GraphicsApiHandler {
		protected:
		
		public:

			virtual void clear_screen() = 0;

			virtual void render() = 0;

			virtual Shader* create_shader(const std::filesystem::path& vertexShaderPath, const std::filesystem::path& fragmentShaderPath) = 0;
			virtual Mesh* create_mesh(std::vector<float>& vertices, std::vector<float>& verticesNormals, std::vector<float>& textureCoordinates, std::vector<unsigned int>& verticesIndex) = 0;
			virtual Texture* create_texture(const std::string& path) = 0;
			virtual Texture* create_texture(const std::string& path, TextureSettings settings) = 0;

	};
}
