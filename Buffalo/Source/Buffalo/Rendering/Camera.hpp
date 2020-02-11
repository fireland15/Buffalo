#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Buffalo {
	namespace Rendering {
		class Camera {
		public:
			Camera(const glm::mat4& view, const glm::mat4& projection);

			virtual ~Camera();

			inline const glm::mat4& GetViewProjectionMatrix() const { return _viewProjectionMatrix; }

			void SetLocation(const glm::vec3& location);

			void SetOrientation(const glm::quat& orientation);

		protected:
			virtual glm::mat4 CalculateViewMatrix() = 0;

			virtual glm::mat4 CalculateProjectionMatrix() = 0;

			glm::mat4 CalculateViewProjectionMatrix();

		protected:
			glm::vec3 _location;

			glm::quat _orientation;

			glm::mat4 _viewMatrix;

			glm::mat4 _projectionMatrix;

			glm::mat4 _viewProjectionMatrix;
		};
	}
}