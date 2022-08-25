#pragma once

#include "CrashEngine/Mesh.hpp"
#include "CrashEngine/Shader.hpp"
#include "CrashEngine/handlers/graphics_api_handler.hpp"

#include "CrashEngine/default-handlers/opengl/OpenGlMesh.hpp"
#include "CrashEngine/default-handlers/opengl/OpenGlShader.hpp"

#include "glad/gl.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

namespace crashengine {
	
	class OpenGlGraphicsApiHandler : public GraphicsApiHandler {
		protected:
		
		public:

			void clearScreen() override;

			void draw() override;

			Shader* createShader(std::set<std::pair<ShaderType, std::string>>& sourceList) override;
			Mesh* storeMeshIntoMemory(std::vector<float>& vertices, std::vector<float>& verticesNormals, std::vector<float>& textureCoordinates, std::vector<unsigned int>& verticesIndex) override;
			void storeTextureIntoMemory() override;			
	};
}