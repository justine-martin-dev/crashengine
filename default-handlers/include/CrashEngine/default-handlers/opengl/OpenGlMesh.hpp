#pragma once

#include "CrashEngine/Mesh.hpp"

#include "CrashEngine/default-handlers/opengl/OpenGlBuffer.hpp"

#include "glad/gl.h"

#include <vector>

namespace crashengine {
	
	class OpenGlMesh : public Mesh {
		protected:

			GLuint id;
			OpenGlBuffer<GLuint> ibo;
			OpenGlBuffer<GLfloat> positions;
			OpenGlBuffer<GLfloat> normals;
			OpenGlBuffer<GLfloat> textureCoordinates;

		public:
			OpenGlMesh(std::vector<float>& vertices, std::vector<float>& verticesNormals, std::vector<float>& textureCoordinates, std::vector<unsigned int>& verticesIndex);
			~OpenGlMesh();

			void bind() override;
			void unbind() override;

			void draw() override;
	};

} 
