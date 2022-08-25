#pragma once

#include "glad/gl.h"

#include <cstddef>
#include <vector>

namespace crashengine {
	
	template <typename T>
	class OpenGlBuffer {
		protected:

			GLuint id;
			GLenum target;

		public:
			OpenGlBuffer(GLenum target);
			virtual ~OpenGlBuffer();

			void bind();
			void unbind();
			
			void setData(std::vector<T>& data);
	};

	template class OpenGlBuffer<GLbyte>;
	template class OpenGlBuffer<GLdouble>;
	template class OpenGlBuffer<GLfloat>;
	template class OpenGlBuffer<GLint>;
	template class OpenGlBuffer<GLshort>;
	template class OpenGlBuffer<GLubyte>;
	template class OpenGlBuffer<GLuint>;
	template class OpenGlBuffer<GLushort>;

} 
