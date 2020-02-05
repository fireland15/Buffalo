#include <Platform/Glfw/GlfwInputAdapter.hpp>
#include <GLFW/glfw3.h>

namespace Buffalo {
	namespace Core {

		GlfwInputAdapter::GlfwInputAdapter(GLFWwindow* window)
			: _window(window) { }

		GlfwInputAdapter::~GlfwInputAdapter() = default;

		bool GlfwInputAdapter::IsKeyPressed(Key key) {
			auto state = glfwGetKey(_window, static_cast<int>(key));
			return state == GLFW_PRESS || state == GLFW_REPEAT;
		}

		bool GlfwInputAdapter::IsMouseButtonPressed(MouseCodes mouseCode) {
			auto state = glfwGetMouseButton(_window, static_cast<int>(mouseCode));
			return state == GLFW_PRESS;
		}

		glm::vec2 GlfwInputAdapter::GetMousePosition() {
			glm::dvec2 pos;
			glfwGetCursorPos(_window, &pos.x, &pos.y);
			return pos;
		}

	}
}