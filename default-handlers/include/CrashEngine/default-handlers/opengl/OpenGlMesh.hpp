#pragma once

#include "CrashEngine/Mesh.hpp"

#include "CrashEngine/default-handlers/opengl/OpenGlBuffer.hpp"

#include "glad/gl.h"

#include <vector>

namespace crashengine {
	
	class OpenGlMesh : public Mesh {
		protected:

			GLuint _id;
			OpenGlBuffer<GLuint> _ibo;
			OpenGlBuffer<GLfloat> _positions;
			OpenGlBuffer<GLfloat> _normals;
			OpenGlBuffer<GLfloat> _textureCoordinates;

		public:
			OpenGlMesh(std::vector<float>& vertices, std::vector<float>& verticesNormals, std::vector<float>& textureCoordinates, std::vector<unsigned int>& verticesIndex);
			~OpenGlMesh();

			void bind() override;
			void unbind() override;

			void draw() override;
	};

} 
