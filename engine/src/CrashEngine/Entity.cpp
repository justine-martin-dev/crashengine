#include "CrashEngine/Entity.hpp"

namespace crashengine {
	
	Entity::Entity() 
			: Entity({0, 0, 0}, {0, 0, 0}, {1, 1, 1}) {
	
	}

	Entity::Entity(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) 
			: position(position),
			  rotation(rotation),
			  scale(scale),
			  modelMatrix(1),
			  isModelMatrixDirty(false) {
		updateMatrix();
	}

	void Entity::updateMatrix() {
		if(this->isModelMatrixDirty) {
			this->modelMatrix = glm::mat4(1);
			this->modelMatrix = glm::translate(this->modelMatrix, this->position);
			this->modelMatrix = glm::rotate(this->modelMatrix, this->rotation[0], {1, 0, 0});
			this->modelMatrix = glm::rotate(this->modelMatrix, this->rotation[1], {0, 1, 0});
			this->modelMatrix = glm::rotate(this->modelMatrix, this->rotation[2], {0, 0, 1});
			this->modelMatrix = glm::scale(this->modelMatrix, this->scale);

			this->isModelMatrixDirty = false;
		}
	}

	void Entity::translate(glm::vec3 translation) {
		this->position += translation;
		
		this->isModelMatrixDirty = true;
	}

	void Entity::translateAndNormalize(glm::vec3 translation, float normalisation) {
		glm::vec3 normalisedTranslation;

		normalisedTranslation.x = translation.x / translation.length();
		normalisedTranslation.y = translation.y / translation.length();
		normalisedTranslation.z = translation.z / translation.length();

		this->translate(normalisedTranslation * normalisation);
	}

	void Entity::rotate(glm::vec3 rotation) {
		this->rotation += rotation;
		
		this->isModelMatrixDirty = true;
	}

	void Entity::rotateDegree(glm::vec3 rotationDegree) {
		this->rotation += glm::radians(rotationDegree);
		
		this->isModelMatrixDirty = true;
	}

	void Entity::setScale(glm::vec3 scale) {
		this->scale = scale;
		
		this->isModelMatrixDirty = true;
	}

	void Entity::setScale(float scale) {
		this->scale = {scale, scale, scale};
		
		this->isModelMatrixDirty = true;
	}

	glm::mat4 Entity::getModelMatrix() {
		return this->modelMatrix;
	}

}