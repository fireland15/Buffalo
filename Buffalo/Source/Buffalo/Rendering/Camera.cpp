#include <Buffalo/Rendering/Camera.hpp>

namespace Buffalo {
	namespace Rendering {
		Camera::Camera(const glm::mat4& view, const glm::mat4& projection)
			: _location(0.f, 0.f, 1.f)
			, _orientation(glm::quatLookAt(glm::vec3(0.f, 0.f, -1.f), glm::vec3(0.f, 1.f, 0.f)))
			, _viewMatrix(view)
			, _projectionMatrix(projection)
			, _viewProjectionMatrix(CalculateViewProjectionMatrix()) {

		}

		Camera::~Camera() = default;

		glm::mat4 Camera::CalculateViewProjectionMatrix() {
			return _projectionMatrix * _viewMatrix;
		}

		void Camera::SetLocation(const glm::vec3& newLocation) {
			_location = newLocation;

			_viewMatrix = CalculateViewMatrix();
			_viewProjectionMatrix = CalculateViewProjectionMatrix();
		}

		void Camera::SetOrientation(const glm::quat& orientation) {
			_orientation = glm::normalize(orientation);

			_viewMatrix = CalculateViewMatrix();
			_viewProjectionMatrix = CalculateViewProjectionMatrix();
		}
	}
}