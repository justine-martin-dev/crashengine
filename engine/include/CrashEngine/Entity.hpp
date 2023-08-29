#pragma once

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

#include "CrashEngine/Mesh.hpp"

namespace crashengine {
	
	class Entity {

		private:

			glm::vec3 position;
			// Rotation is in radians
			glm::vec3 rotation;
			glm::vec3 scale;

			glm::mat4 modelMatrix;

			bool isModelMatrixDirty;
			
		public:

			Entity();
			Entity(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);

			void translate(glm::vec3 translation);
			void translateAndNormalize(glm::vec3 translation, float normalisation);

			void rotate(glm::vec3 rotation);
			void rotateDegree(glm::vec3 rotationDegree);

			void setScale(glm::vec3 scale);
			void setScale(float scale);

			void updateMatrix();
			glm::mat4 getModelMatrix();
	};

}