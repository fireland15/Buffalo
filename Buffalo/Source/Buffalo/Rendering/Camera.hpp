#pragma once

#include <glm/glm.hpp>

namespace Buffalo {
	namespace Rendering {
		class Camera {
		public:
			Camera(const glm::mat4& view, const glm::mat4& projection);

			virtual ~Camera();

			inline const glm::mat4& GetViewProjectionMatrix() const { return viewProjectionMatrix; }

			void SetLocation(const glm::vec3& location);

		protected:
			virtual glm::mat4 CalculateViewMatrix() = 0;

			virtual glm::mat4 CalculateProjectionMatrix() = 0;

			glm::mat4 CalculateViewProjectionMatrix();

		protected:
			glm::vec3 location;

			glm::mat4 viewMatrix;

			glm::mat4 projectionMatrix;

			glm::mat4 viewProjectionMatrix;
		};
	}
}