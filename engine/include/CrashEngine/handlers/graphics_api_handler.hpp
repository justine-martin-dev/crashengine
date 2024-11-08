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

			virtual void clearScreen() = 0;

			virtual void render() = 0;

			virtual Shader* createShader(const std::filesystem::path& vertex_shader_path, const std::filesystem::path& fragment_shader_path) = 0;
			virtual Mesh* createMesh(std::vector<float>& vertices, std::vector<float>& verticesNormals, std::vector<float>& textureCoordinates, std::vector<unsigned int>& verticesIndex) = 0;
			virtual Texture* createTexture(const std::string& path) = 0;
			virtual Texture* createTexture(const std::string& path, TextureSettings settings) = 0;

	};
}
