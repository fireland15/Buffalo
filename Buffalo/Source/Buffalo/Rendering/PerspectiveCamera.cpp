#include <Buffalo/Rendering/PerspectiveCamera.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Buffalo {
	namespace Rendering {
		PerspectiveCamera::PerspectiveCamera(float aspectRatio)
			: _aspectRatio(aspectRatio)
			, Camera(glm::mat4(), glm::mat4()) {
			_viewMatrix = CalculateViewMatrix();
			_projectionMatrix = CalculateProjectionMatrix();
			_viewProjectionMatrix = CalculateViewProjectionMatrix();
		}

		glm::mat4 PerspectiveCamera::CalculateViewMatrix() {
			glm::mat4 rotation = glm::mat4_cast(_orientation);
			glm::mat4 translation = glm::translate(glm::mat4(1.f), -_location);
			return rotation * translation;
		}

		glm::mat4 PerspectiveCamera::CalculateProjectionMatrix() {
			return glm::perspective(glm::radians(45.f), _aspectRatio, 0.01f, 100.f);
		}
	}
}
