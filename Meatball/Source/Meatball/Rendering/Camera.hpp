#pragma once

#include <glm/glm.hpp>

namespace Meatball {
	namespace Rendering {
		class Camera {
		public:
			Camera(const glm::mat4& m)
				: matrix(m) { }

			virtual ~Camera() = default;

			const glm::mat4& ViewProjectionMatrix() const {
				return matrix;
			}

		private:
			glm::mat4 matrix;
		};
	}
}