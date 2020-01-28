#pragma once

#include <glm/glm.hpp>

namespace Meatball {
	namespace Rendering {
		class Camera {
		public:
			Camera(const glm::mat4&){ }

			virtual ~Camera() = default;

			const glm::mat4& ViewProjectionMatrix() const {
				return glm::mat4(1.f);
			}

		protected:

		};
	}
}