#include <Buffalo/Rendering/CameraController.hpp>
#include <Buffalo/Core/TimeStep.hpp>
#include <Buffalo/Rendering/Camera.hpp>

namespace Buffalo {
	namespace Rendering {

		CameraController::CameraController(Camera& camera)
			: camera(camera) { }

		CameraController::~CameraController() = default;

	}
}