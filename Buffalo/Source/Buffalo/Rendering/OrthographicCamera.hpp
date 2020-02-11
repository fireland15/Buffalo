#pragma once

#include <Buffalo/Rendering/Camera.hpp>

namespace Buffalo {
	namespace Rendering {
		class OrthographicCamera : public Camera {
		public:
			OrthographicCamera(float aspectRatio);

		protected:
			virtual glm::mat4 CalculateViewMatrix() override;

			virtual glm::mat4 CalculateProjectionMatrix() override;

		private:
			float _aspectRatio;
		};
	}
}