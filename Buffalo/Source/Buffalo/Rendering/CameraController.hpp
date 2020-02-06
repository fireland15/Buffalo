#pragma once

namespace Buffalo {
	namespace Core {
		class TimeStep;
	}

	namespace Rendering {

		class Camera;

		class CameraController {
		public:
			CameraController(Camera& camera);

			virtual ~CameraController();

			virtual void OnUpdate(const Core::TimeStep& timeStep) = 0;

		protected:
			Camera& camera;
		};

	}
}