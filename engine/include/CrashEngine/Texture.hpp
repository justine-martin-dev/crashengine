#pragma once

#include <string>

namespace crashengine {

	enum TextureWrapping {
		REPEAT = 0, MIRRORED_REPEAT = 1, CLAMP_TO_EDGE = 2, CLAMP_TO_BORDER = 3
	};

	enum Filtering {
		NEAREST = 0, LINEAR = 1
	};

	struct TextureSettings {

		Filtering textureFiltering = Filtering::LINEAR;
		TextureWrapping textureWrapping = TextureWrapping::REPEAT;
		Filtering mipMapFiltering = Filtering::LINEAR;
		
		bool shouldGenerateMipmap = true;

	};

	class Texture {

		protected:

			TextureSettings textureSettings;

		public:

			Texture(TextureSettings TextureSettings);
			
			virtual void bind(std::size_t textureSlot) = 0;
			virtual void unbind() = 0;

	};

}