#pragma once

#include "CrashEngine/Shader.hpp"

#include "glad/gl.h"

namespace crashengine {

	class OpenGlShader  : public Shader {

		protected:

			GLuint id;

		public:

			OpenGlShader();
			~OpenGlShader();

			void bind() override;
			void unbind() override;

			void attachShader(GLuint shaderId);
			void linkProgram();

	};

}