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

		void Camera::UpdateMatrices(const UpdateMatricesUsingOrientation& params) {
			_location = params.position;
			_orientation = params.orientation;

			_viewMatrix = CalculateViewMatrix();
			_viewProjectionMatrix = CalculateViewProjectionMatrix();
		}

		void Camera::UpdateMatrices(const UpdateMatricesUsingLookAt& params) {
			_location = params.position;
			_orientation = glm::quatLookAt(glm::normalize(params.lookAt - params.position), glm::vec3(0.f, 1.f, 0.f));

			_viewMatrix = glm::lookAt(_location, params.lookAt, glm::vec3(0.f, 1.f, 0.f));
			_viewProjectionMatrix = CalculateViewProjectionMatrix();
		}

		Camera::UpdateMatricesUsingLookAt::UpdateMatricesUsingLookAt(const glm::vec3& position, const glm::vec3& lookAt)
			: position(position), lookAt(lookAt) { }
	}
}