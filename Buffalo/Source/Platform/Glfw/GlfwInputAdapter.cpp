#include <Platform/Glfw/GlfwInputAdapter.hpp>
#include <Buffalo/Core/Debug.hpp>
#include <GLFW/glfw3.h>

namespace Buffalo {
	namespace Core {

		GlfwInputAdapter::GlfwInputAdapter(GLFWwindow* window)
			: _window(window) {
			BUFFALO_PROFILE_FUNC();
		}

		GlfwInputAdapter::~GlfwInputAdapter() = default;

		bool GlfwInputAdapter::IsKeyPressed(Key key) {
			BUFFALO_PROFILE_FUNC();
			auto state = glfwGetKey(_window, static_cast<int>(key));
			return state == GLFW_PRESS || state == GLFW_REPEAT;
		}

		bool GlfwInputAdapter::IsMouseButtonPressed(MouseCodes mouseCode) {
			BUFFALO_PROFILE_FUNC();
			auto state = glfwGetMouseButton(_window, static_cast<int>(mouseCode));
			return state == GLFW_PRESS;
		}

		glm::vec2 GlfwInputAdapter::GetMousePosition() {
			BUFFALO_PROFILE_FUNC();
			glm::dvec2 pos;
			glfwGetCursorPos(_window, &pos.x, &pos.y);
			return pos;
		}

	}
}