#include "CrashEngine/Camera.hpp"

#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/trigonometric.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/trigonometric.hpp>

namespace crashengine {

    Camera::Camera()
        : Camera({ 0, 0, 0 }, { 0, 0, 0 })
    {
    }

    Camera::Camera(glm::vec3 position, glm::vec3 rotationRadian)
        : _position(position)
        , _rotationRadian(rotationRadian)
        , _isViewMatrixDusty(true)
    {
        this->update_view_matrix();
    }

    Camera::~Camera()
    {
    }

    void Camera::translate(const glm::vec3& translation)
    {
        this->_position += translation;

        this->_isViewMatrixDusty = true;
    }

    void Camera::rotate(const glm::vec3& radian_rotation)
    {
        this->_rotationRadian += radian_rotation;

        this->_isViewMatrixDusty = true;
    }

    void Camera::rotate_degree(const glm::vec3& rotationDegree)
    {
        this->_rotationRadian += glm::radians(rotationDegree);

        this->_isViewMatrixDusty = true;
    }

    glm::vec3 Camera::position() const
    {
        return this->_position;
    }

    void Camera::position(const glm::vec3& position)
    {
        this->_position = position;

        this->_isViewMatrixDusty = true;
    }

    glm::vec3 Camera::rotation() const
    {
        return this->_rotationRadian;
    }

    void Camera::rotation(const glm::vec3& rotation)
    {
        this->_rotationRadian = rotation;

        this->_isViewMatrixDusty = true;
    }

    void Camera::rotation_degree(const glm::vec3& rotation_degree)
    {
        this->_rotationRadian = glm::radians(rotation_degree);

        this->_isViewMatrixDusty = true;
    }

    glm::mat4 Camera::view_matrix() const
    {
        return this->_viewMatrix;
    }

    void Camera::update_view_matrix()
    {
        if (this->_isViewMatrixDusty) {
            this->_viewMatrix = glm::mat4(1);
            this->_viewMatrix = glm::translate(this->_viewMatrix, this->_position);
            this->_viewMatrix = glm::rotate(this->_viewMatrix, this->_rotationRadian[0], { 1, 0, 0 });
            this->_viewMatrix = glm::rotate(this->_viewMatrix, this->_rotationRadian[1], { 0, 1, 0 });
            this->_viewMatrix = glm::rotate(this->_viewMatrix, this->_rotationRadian[2], { 0, 0, 1 });

            this->_isViewMatrixDusty = false;
        }
    }

    glm::mat4 Camera::projection_matrix() const
    {
        return this->_projectionMatrix;
    }

    OrthographicCamera::OrthographicCamera(glm::vec3 position, glm::vec3 rotationRadian, int top, int bottom, int left, int right, float near, float far)
        : Camera(position, rotationRadian)
        , _top(top)
        , _bottom(bottom)
        , _left(left)
        , _right(right)
        , _near(near)
        , _far(far)
        , _isProjectionMatrixDusty(true)
    {
        this->update_projection_matrix();
    }

    OrthographicCamera::~OrthographicCamera()
    {
    }

    void OrthographicCamera::update_projection_matrix()
    {
        if (this->_isProjectionMatrixDusty) {
            this->_projectionMatrix = glm::ortho(this->_left, this->_right, this->_bottom, this->_top, this->_near, this->_far);

            this->_isProjectionMatrixDusty = false;
        }
    }

    int OrthographicCamera::top() const
    {
        return this->_top;
    }

    void OrthographicCamera::top(int top)
    {
        this->_top = top;

        this->_isProjectionMatrixDusty = true;
    }

    int OrthographicCamera::bottom() const
    {
        return this->_bottom;
    }

    void OrthographicCamera::bottom(int bottom)
    {
        this->_bottom = bottom;

        this->_isProjectionMatrixDusty = true;
    }

    int OrthographicCamera::left() const
    {
        return this->_left;
    }

    void OrthographicCamera::left(int left)
    {
        this->_left = left;

        this->_isProjectionMatrixDusty = true;
    }

    int OrthographicCamera::right() const
    {
        return this->_right;
    }

    void OrthographicCamera::right(int right)
    {
        this->_right = right;

        this->_isProjectionMatrixDusty = true;
    }

    int OrthographicCamera::near() const
    {
        return this->_near;
    }

    void OrthographicCamera::near(int near)
    {
        this->_near = near;

        this->_isProjectionMatrixDusty = true;
    }

    int OrthographicCamera::far() const
    {
        return this->_far;
    }

    void OrthographicCamera::far(int far)
    {
        this->_far = far;

        this->_isProjectionMatrixDusty = true;
    }

    PerspectiveCamera::PerspectiveCamera(glm::vec3 position, glm::vec3 rotationRadian, float fov, float aspectRatio, float near, float far)
        : Camera(position, rotationRadian)
        , _fov(fov)
        , _aspectRatio(aspectRatio)
        , _near(near)
        , _far(far)
        , _isProjectionMatrixDusty(true)
    {
        this->update_projection_matrix();
    }

    PerspectiveCamera::~PerspectiveCamera()
    {
    }

    void PerspectiveCamera::update_projection_matrix()
    {
        if (this->_isProjectionMatrixDusty) {
            this->_projectionMatrix = glm::perspective(glm::radians(this->_fov), this->_aspectRatio, this->_near, this->_far);

            this->_isProjectionMatrixDusty = false;
        }
    }

    float PerspectiveCamera::fov() const
    {
        return this->_fov;
    }

    void PerspectiveCamera::fov(float fov)
    {
        this->_fov = fov;

        this->_isProjectionMatrixDusty = true;
    }

    float PerspectiveCamera::aspect_ratio() const
    {
        return this->_aspectRatio;
    }

    void PerspectiveCamera::aspect_ratio(float aspectRatio)
    {
        this->_aspectRatio = aspectRatio;

        this->_isProjectionMatrixDusty = true;
    }

    float PerspectiveCamera::near() const
    {
        return this->_near;
    }

    void PerspectiveCamera::near(float near)
    {
        this->_near = near;

        this->_isProjectionMatrixDusty = true;
    }

    float PerspectiveCamera::far() const
    {
        return this->_far;
    }

    void PerspectiveCamera::far(float far)
    {
        this->_far = far;

        this->_isProjectionMatrixDusty = true;
    }
}
