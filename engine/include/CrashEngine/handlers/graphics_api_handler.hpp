#pragma once

#include "CrashEngine/Mesh.hpp"
#include "CrashEngine/Shader.hpp"
#include "CrashEngine/Texture.hpp"

#include <set>
#include <string>
#include <utility>
#include <vector>

namespace crashengine {

	enum ShaderType {
		VERTEX, GEOMETRY, FRAGMENT
	};

	class GraphicsApiHandler {
		protected:
		
		public:

			virtual void clearScreen() = 0;

			virtual void draw() = 0;

			virtual Shader* createShader(std::set<std::pair<ShaderType, std::string>>& sourceList) = 0;
			virtual Mesh* storeMeshIntoMemory(std::vector<float>& vertices, std::vector<float>& verticesNormals, std::vector<float>& textureCoordinates, std::vector<unsigned int>& verticesIndex) = 0;
			virtual Texture* storeTextureIntoMemory(const std::string& path) = 0;
			virtual Texture* storeTextureIntoMemory(const std::string& path, TextureSettings settings) = 0;

	};
}