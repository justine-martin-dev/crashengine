#pragma once

#include <glm/vec3.hpp> 
#include <glm/vec4.hpp> 
#include <glm/mat4x4.hpp> 
#include <glm/ext/matrix_transform.hpp> 
#include <glm/ext/matrix_clip_space.hpp> 
#include <glm/ext/scalar_constants.hpp> 

namespace crashengine {
	
	class Entity {

		private:

			glm::vec3 position;
			// Rotation is in radians
			glm::vec3 radian_rotation;
			glm::vec3 proportions;

			glm::mat4 modelMatrix;

			bool isModelMatrixDusty;
			
		public:

			Entity();
			Entity(const glm::vec3& position, const glm::vec3& radian_rotation, const glm::vec3& scale);

			void translate(const glm::vec3& translation);
			void translateAndNormalize(const glm::vec3& rawDirection, const float length);

			void rotate(const glm::vec3& radian_rotation);
			void rotateDegree(const glm::vec3& rotationDegree);

			void scale(const glm::vec3& scaling);
			void scale(const float scaling);
			
			glm::vec3 getPosition() const;
			void setPosition(const glm::vec3& position);

			glm::vec3 getRotation() const;
			void setRotation(const glm::vec3& rotation);
			void setRotationDegree(const glm::vec3& rotation_degree);
			
			glm::vec3 getScale() const;
			void setScale(const glm::vec3& scale);
			void setScale(const float scale);

			void updateMatrix();
			glm::mat4 getModelMatrix() const;
	};

}
