#pragma once

namespace crashengine {

	class Shader {

		public:

			virtual void bind() = 0;
			virtual void unbind() = 0;

	};

}