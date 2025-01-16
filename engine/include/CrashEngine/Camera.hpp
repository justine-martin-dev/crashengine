#pragma once

#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"

namespace crashengine {

    class Camera {
        private:

            glm::vec3 _position;
            glm::vec3 _rotationRadian;

			glm::mat4 _viewMatrix;
			bool      _isViewMatrixDusty;

        protected:

			glm::mat4 _projectionMatrix;

        public:
            
            Camera();
            Camera(glm::vec3 position, glm::vec3 rotationRadian);
            virtual ~Camera();

			void translate(const glm::vec3& translation);

			void rotate(const glm::vec3& radianRotation);
			void rotate_degree(const glm::vec3& rotationDegree);

			glm::vec3 position() const;
			void position(const glm::vec3& position);

			glm::vec3 rotation() const;
			void rotation(const glm::vec3& rotation);
			void rotation_degree(const glm::vec3& rotationDegree);

            glm::mat4 projection_matrix() const;
            glm::mat4 view_matrix() const;
			void update_view_matrix();
			virtual void update_projection_matrix() = 0;
    };

    class OrthographicCamera : public Camera {
        private:

            int   _top, _bottom, _left, _right;
            int _near, _far;

            bool _isProjectionMatrixDusty; 

        public:

            OrthographicCamera(glm::vec3 position, glm::vec3 rotationRadian, int top, int bottom, int left, int right, float near, float far);
            ~OrthographicCamera() override;

            int top() const;
            void top(int top);
            int bottom() const;
            void bottom(int bottom);
            int left() const;
            void left(int left);
            int right() const;
            void right(int right);

            int near() const;
            void near(int near);
            int far() const;
            void far(int far);

            void update_projection_matrix() override;
    };

    class PerspectiveCamera : public Camera {
        private:

            float _fov;
            float _aspectRatio;
            float _near, _far;

            bool _isProjectionMatrixDusty;
            
        public:

            PerspectiveCamera(glm::vec3 position, glm::vec3 rotationRadian, float fov, float aspectRatio, float near, float far);
            ~PerspectiveCamera() override;

            void update_projection_matrix() override;

            float fov() const;
            void fov(float fov);
            float aspect_ratio() const;
            void aspect_ratio(float aspectRatio);
            float near() const;
            void near(float near);
            float far() const;
            void far(float far);
    };
}
