#pragma once

#include <glm/glm.hpp>
#include <Buffalo/Core/Keys.hpp>
#include <Buffalo/Core/MouseCodes.hpp>

namespace Buffalo {
	namespace Core {
		class WindowInputAdapter {
		public:
			virtual ~WindowInputAdapter();

			virtual bool IsKeyPressed(Key key) = 0;

			virtual bool IsMouseButtonPressed(MouseCodes mouseCode) = 0;

			virtual glm::vec2 GetMousePosition() = 0;
		};
	}
}