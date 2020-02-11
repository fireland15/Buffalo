#include <Buffalo/Rendering/OrthographicCamera.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Buffalo {
	namespace Rendering {
		OrthographicCamera::OrthographicCamera(float aspectRatio)
			: _aspectRatio(aspectRatio)
			, Camera(glm::mat4(), glm::mat4()) {
			_viewMatrix = CalculateViewMatrix();
			_projectionMatrix = CalculateProjectionMatrix();
			_viewProjectionMatrix = CalculateViewProjectionMatrix();
		}

		glm::mat4 OrthographicCamera::CalculateViewMatrix() {
			glm::mat4 rotation = glm::mat4_cast(_orientation);
			glm::mat4 translation = glm::translate(glm::mat4(1.f), -_location);
			return rotation * translation;
		}

		glm::mat4 OrthographicCamera::CalculateProjectionMatrix() {
			return glm::ortho(-_aspectRatio, _aspectRatio, -1.f, 1.f, 0.0001f, 100.0f);
		}
	}
}
