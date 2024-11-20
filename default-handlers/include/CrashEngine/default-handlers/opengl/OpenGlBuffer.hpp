#pragma once

#include "glad/gl.h"

#include <cstddef>
#include <vector>

namespace crashengine {
	
	template <typename T>
	class OpenGlBuffer {
		protected:

			GLuint _id;
			GLenum _target;
			std::size_t _size;

		public:
			OpenGlBuffer(GLenum target);
			virtual ~OpenGlBuffer();

			void bind();
			void unbind();
			
			void data(std::vector<T>& data);
			std::size_t size();
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
