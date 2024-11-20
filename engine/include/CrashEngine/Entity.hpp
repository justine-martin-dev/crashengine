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

			glm::vec3 _position;
			// Rotation is in radians
			glm::vec3 _radian_rotation;
			glm::vec3 _proportions;

			glm::mat4 _modelMatrix;

			bool _isModelMatrixDusty;
			
		public:

			Entity();
			Entity(const glm::vec3& position, const glm::vec3& radianRotation, const glm::vec3& scale);

			void translate(const glm::vec3& translation);
			void translate_and_normalize(const glm::vec3& rawDirection, const float length);

			void rotate(const glm::vec3& radianRotation);
			void rotate_degree(const glm::vec3& rotationDegree);

			void scale(const glm::vec3& scaling);
			void scale(const float scaling);
			
			glm::vec3 position() const;
			void position(const glm::vec3& position);

			glm::vec3 rotation() const;
			void rotation(const glm::vec3& rotation);
			void rotation_degree(const glm::vec3& rotationDegree);
			
			glm::vec3 proportions() const;
			void proportions(const glm::vec3& scale);
			void proportions(const float scale);

			void update_matrix();
			glm::mat4 model_matrix() const;
	};

}
