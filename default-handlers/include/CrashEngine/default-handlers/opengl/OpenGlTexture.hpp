#pragma once

#include "CrashEngine/Texture.hpp"
#include "CrashEngine/logger.hpp"

#include "glad/gl.h"

#include "stb_image.h"

namespace crashengine {

	class OpenGlTexture : public Texture {
		
		protected:

			GLuint id;

		public:

			OpenGlTexture(const std::string& path, TextureSettings textureSettings);

			void bind(std::size_t textureSlot) override;
			void unbind() override;
	};

}
