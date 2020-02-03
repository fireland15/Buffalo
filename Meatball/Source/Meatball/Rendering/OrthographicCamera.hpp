#pragma once

#include <Meatball/Rendering/Camera.hpp>

namespace Meatball {
	namespace Rendering {
		class OrthographicCamera : public Camera {
		public:
			OrthographicCamera(float aspectRatio);

		protected:
			virtual glm::mat4 CalculateViewMatrix() override;

			virtual glm::mat4 CalculateProjectionMatrix() override;

		private:
			float aspectRatio;
		};
	}
}