#pragma once

#include "CrashEngine/Texture.hpp"

#include "glad/gl.h"

#include "stb_image.h"

#include <string>

namespace crashengine {

	class OpenGlTexture : public Texture {
		
		protected:

			GLuint _id;

		public:

			OpenGlTexture(const std::string& path, TextureSettings textureSettings);

			void bind_to_slot(std::size_t textureSlot) override;
			void unbind(std::size_t textureSlot) override;
	};

}
