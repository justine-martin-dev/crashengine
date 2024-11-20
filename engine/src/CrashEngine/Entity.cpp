#include "CrashEngine/Entity.hpp"
#include <glm/trigonometric.hpp>

namespace crashengine {

    Entity::Entity()
        : Entity({ 0, 0, 0 }, { 0, 0, 0 }, { 1, 1, 1 })
    {
    }

    Entity::Entity(const glm::vec3& position, const glm::vec3& radian_rotation, const glm::vec3& scale)
        : position(position)
        , radian_rotation(radian_rotation)
        , proportions(scale)
        , modelMatrix(1)
        , isModelMatrixDusty(true)
    {
        updateMatrix();
    }

    void Entity::updateMatrix()
    {
        if (this->isModelMatrixDusty) {
            this->modelMatrix = glm::mat4(1);
            this->modelMatrix = glm::translate(this->modelMatrix, this->position);
            this->modelMatrix = glm::rotate(this->modelMatrix, this->radian_rotation[0], { 1, 0, 0 });
            this->modelMatrix = glm::rotate(this->modelMatrix, this->radian_rotation[1], { 0, 1, 0 });
            this->modelMatrix = glm::rotate(this->modelMatrix, this->radian_rotation[2], { 0, 0, 1 });
            this->modelMatrix = glm::scale(this->modelMatrix, this->proportions);

            this->isModelMatrixDusty = false;
        }
    }

    void Entity::translate(const glm::vec3& translation)
    {
        this->position += translation;

        this->isModelMatrixDusty = true;
    }

    void Entity::translateAndNormalize(const glm::vec3& rawDirection, const float length)
    {
        glm::vec3 normalisedTranslation;

        float rawDirectionLength = rawDirection.length();
        normalisedTranslation.x  = rawDirection.x / rawDirectionLength;
        normalisedTranslation.y  = rawDirection.y / rawDirectionLength;
        normalisedTranslation.z  = rawDirection.z / rawDirectionLength;

        this->position += normalisedTranslation * length;

        this->isModelMatrixDusty = true;
    }

    void Entity::rotate(const glm::vec3& radian_rotation)
    {
        this->radian_rotation += radian_rotation;

        this->isModelMatrixDusty = true;
    }

    void Entity::rotateDegree(const glm::vec3& rotationDegree)
    {
        this->radian_rotation += glm::radians(rotationDegree);

        this->isModelMatrixDusty = true;
    }

    void Entity::scale(const glm::vec3& scaling)
    {
        this->proportions += scaling;

        this->isModelMatrixDusty = true;
    }

    void Entity::scale(const float scaling)
    {
        this->proportions += glm::vec3 { scaling, scaling, scaling };

        this->isModelMatrixDusty = true;
    }

    glm::vec3 Entity::getPosition() const
    {
        return this->position;
    }

    void Entity::setPosition(const glm::vec3& position)
    {
        this->position = position;

        this->isModelMatrixDusty = true;
    }

    glm::vec3 Entity::getRotation() const
    {
        return this->radian_rotation;
    }

    void Entity::setRotation(const glm::vec3& rotation)
    {
        this->radian_rotation = rotation;

        this->isModelMatrixDusty = true;
    }

    void Entity::setRotationDegree(const glm::vec3& rotation_degree)
    {
        this->radian_rotation = glm::radians(rotation_degree);

        this->isModelMatrixDusty = true;
    }

    glm::vec3 Entity::getScale() const
    {
        return this->proportions;
    }

    void Entity::setScale(const glm::vec3& scale)
    {
        this->proportions = scale;

        this->isModelMatrixDusty = true;
    }

    void Entity::setScale(const float scale)
    {
        this->proportions = { scale, scale, scale };

        this->isModelMatrixDusty = true;
    }

    glm::mat4 Entity::getModelMatrix() const
    {
        return this->modelMatrix;
    }

}
