#pragma once

#include <glm/glm.hpp>
#include <Buffalo/Core/Keys.hpp>
#include <Buffalo/Core/MouseCodes.hpp>

namespace Buffalo {
	namespace Core {
		class WindowInputAdapter;
	}

	class InputState {
	public:
		static void SetAdapter(Core::WindowInputAdapter* adapter);

		static void ReleaseAdapter();

		static bool IsKeyPressed(Key key);

		static bool IsMouseButtonPressed(MouseCodes mouseCode);

		static glm::vec2 GetMousePosition();

	private:
		static Core::WindowInputAdapter* adapter;
	};
}