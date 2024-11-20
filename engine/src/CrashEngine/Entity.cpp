#include "CrashEngine/Entity.hpp"
#include <glm/trigonometric.hpp>

namespace crashengine {

    Entity::Entity()
        : Entity({ 0, 0, 0 }, { 0, 0, 0 }, { 1, 1, 1 })
    {
    }

    Entity::Entity(const glm::vec3& position, const glm::vec3& radian_rotation, const glm::vec3& scale)
        : _position(position)
        , _radian_rotation(radian_rotation)
        , _proportions(scale)
        , _modelMatrix(1)
        , _isModelMatrixDusty(true)
    {
        this->update_matrix();
    }

    void Entity::update_matrix()
    {
        if (this->_isModelMatrixDusty) {
            this->_modelMatrix = glm::mat4(1);
            this->_modelMatrix = glm::translate(this->_modelMatrix, this->_position);
            this->_modelMatrix = glm::rotate(this->_modelMatrix, this->_radian_rotation[0], { 1, 0, 0 });
            this->_modelMatrix = glm::rotate(this->_modelMatrix, this->_radian_rotation[1], { 0, 1, 0 });
            this->_modelMatrix = glm::rotate(this->_modelMatrix, this->_radian_rotation[2], { 0, 0, 1 });
            this->_modelMatrix = glm::scale(this->_modelMatrix, this->_proportions);

            this->_isModelMatrixDusty = false;
        }
    }

    void Entity::translate(const glm::vec3& translation)
    {
        this->_position += translation;

        this->_isModelMatrixDusty = true;
    }

    void Entity::translate_and_normalize(const glm::vec3& rawDirection, const float length)
    {
        glm::vec3 normalisedTranslation;

        float rawDirectionLength = rawDirection.length();
        normalisedTranslation.x  = rawDirection.x / rawDirectionLength;
        normalisedTranslation.y  = rawDirection.y / rawDirectionLength;
        normalisedTranslation.z  = rawDirection.z / rawDirectionLength;

        this->_position += normalisedTranslation * length;

        this->_isModelMatrixDusty = true;
    }

    void Entity::rotate(const glm::vec3& radian_rotation)
    {
        this->_radian_rotation += radian_rotation;

        this->_isModelMatrixDusty = true;
    }

    void Entity::rotate_degree(const glm::vec3& rotationDegree)
    {
        this->_radian_rotation += glm::radians(rotationDegree);

        this->_isModelMatrixDusty = true;
    }

    void Entity::scale(const glm::vec3& scaling)
    {
        this->_proportions += scaling;

        this->_isModelMatrixDusty = true;
    }

    void Entity::scale(const float scaling)
    {
        this->_proportions += glm::vec3 { scaling, scaling, scaling };

        this->_isModelMatrixDusty = true;
    }

    glm::vec3 Entity::position() const
    {
        return this->_position;
    }

    void Entity::position(const glm::vec3& position)
    {
        this->_position = position;

        this->_isModelMatrixDusty = true;
    }

    glm::vec3 Entity::rotation() const
    {
        return this->_radian_rotation;
    }

    void Entity::rotation(const glm::vec3& rotation)
    {
        this->_radian_rotation = rotation;

        this->_isModelMatrixDusty = true;
    }

    void Entity::rotation_degree(const glm::vec3& rotation_degree)
    {
        this->_radian_rotation = glm::radians(rotation_degree);

        this->_isModelMatrixDusty = true;
    }

    glm::vec3 Entity::proportions() const
    {
        return this->_proportions;
    }

    void Entity::proportions(const glm::vec3& scale)
    {
        this->_proportions = scale;

        this->_isModelMatrixDusty = true;
    }

    void Entity::proportions(const float scale)
    {
        this->_proportions = { scale, scale, scale };

        this->_isModelMatrixDusty = true;
    }

    glm::mat4 Entity::model_matrix() const
    {
        return this->_modelMatrix;
    }

}
