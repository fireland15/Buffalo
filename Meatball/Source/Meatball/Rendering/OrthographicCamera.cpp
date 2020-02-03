#include <Meatball/Rendering/OrthographicCamera.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Meatball {
	namespace Rendering {
		OrthographicCamera::OrthographicCamera(float aspectRatio)
			: aspectRatio(aspectRatio)
			, Camera(glm::mat4(), glm::mat4()) {
			viewMatrix = CalculateViewMatrix();
			projectionMatrix = CalculateProjectionMatrix();
			viewProjectionMatrix = CalculateViewProjectionMatrix();
		}

		glm::mat4 OrthographicCamera::CalculateViewMatrix() {
			return glm::lookAt(location, glm::vec3(0.f), glm::vec3(0.f, 1.f, 0.f));
		}

		glm::mat4 OrthographicCamera::CalculateProjectionMatrix() {
			return glm::ortho(-aspectRatio, aspectRatio, -1.f, 1.f, 0.0001f, 100.0f);
		}
	}
}
