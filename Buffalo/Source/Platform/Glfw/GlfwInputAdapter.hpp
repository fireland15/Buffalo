#pragma once

#include <Buffalo/Core/WindowInputAdapter.hpp>

struct GLFWwindow;

namespace Buffalo {
	namespace Core {
		class GlfwInputAdapter : public WindowInputAdapter {
		public:
			GlfwInputAdapter(GLFWwindow* window);

			virtual ~GlfwInputAdapter();

			virtual bool IsKeyPressed(Key key);

			virtual bool IsMouseButtonPressed(MouseCodes mouseCode);

			virtual glm::vec2 GetMousePosition();

		private:
			GLFWwindow* _window;
		};
	}
}