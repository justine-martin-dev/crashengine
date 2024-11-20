#pragma once

namespace crashengine {
	
	class Mesh {
		protected:

		public:
			virtual ~Mesh() = default;

			virtual void bind() = 0;
			virtual void unbind() = 0;

			virtual void draw() = 0;
	};

}
