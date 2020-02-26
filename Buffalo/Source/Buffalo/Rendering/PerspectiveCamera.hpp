#pragma once

#include <Buffalo/Rendering/Camera.hpp>

namespace Buffalo {
	namespace Rendering {
		class PerspectiveCamera : public Camera {
		public:
			PerspectiveCamera(float aspectRatio);

		protected:
			virtual glm::mat4 CalculateViewMatrix() override;

			virtual glm::mat4 CalculateProjectionMatrix() override;

		private:
			float _aspectRatio;
		};
	}
}