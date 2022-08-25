#include "CrashEngine/default-handlers/opengl.hpp"

namespace crashengine {

	void OpenGlGraphicsApiHandler::clearScreen() {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0, 0, 0, 1);
	}

	void OpenGlGraphicsApiHandler::draw() {
		
	}

	Shader* OpenGlGraphicsApiHandler::createShader(std::set<std::pair<ShaderType, std::string>>& sourceList) {
		std::vector<GLuint> shadersIds(sourceList.size());
		
		OpenGlShader* shader = new OpenGlShader();
		int i = 0;
		std::for_each(sourceList.begin(), sourceList.end(), [&shadersIds, &shader, &i](std::pair<ShaderType, std::string> source) {
			switch(source.first) {
				case VERTEX:
					shadersIds[i] = glCreateShader(GL_VERTEX_SHADER);
					break;

				case FRAGMENT:
					shadersIds[i] = glCreateShader(GL_FRAGMENT_SHADER);
					break;

				case GEOMETRY:
					shadersIds[i] = glCreateShader(GL_GEOMETRY_SHADER);
					break;
			}

			std::ifstream shaderFileStream(source.second);
			if(!shaderFileStream) {
				std::cerr << "Couldn't find " << source.second << std::endl;
			}
			std::string sourceCode((std::istreambuf_iterator<char>(shaderFileStream)), std::istreambuf_iterator<char>());
			const char *sourceCodeCStr = sourceCode.c_str(); 

			glShaderSource(shadersIds[i], 1, &sourceCodeCStr, NULL);
			glCompileShader(shadersIds[i]);

			shader->attachShader(shadersIds[i]);

			i++;
		});

		shader->linkProgram();

		std::for_each(shadersIds.begin(), shadersIds.end(), [](GLuint idShader) {
			glDeleteShader(idShader);
		});
		
		return shader;
	}

	Mesh* OpenGlGraphicsApiHandler::storeMeshIntoMemory(std::vector<float>& vertices, std::vector<float>& verticesNormals, std::vector<float>& textureCoordinates, std::vector<unsigned int>& verticesIndex) {
		return new OpenGlMesh(vertices, verticesNormals, textureCoordinates, verticesIndex);
	}

	void OpenGlGraphicsApiHandler::storeTextureIntoMemory() {
		
	}

}