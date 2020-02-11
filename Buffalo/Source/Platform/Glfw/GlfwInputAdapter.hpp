#pragma once

#include <Buffalo/Core/WindowInputAdapter.hpp>
#include <Buffalo/Core/TypeDefs.hpp>
#include <glm/glm.hpp>
#include <map>

struct GLFWwindow;

namespace Buffalo {
	namespace Events {
		class Event;
		class EventDispatcher;
	}

	namespace Core {
		class GlfwInputAdapter : public WindowInputAdapter {
		public:
			GlfwInputAdapter(GLFWwindow* window);

			virtual ~GlfwInputAdapter();

			virtual bool IsKeyPressed(Key key);

			virtual bool IsMouseButtonPressed(MouseCodes mouseCode);

			virtual glm::vec2 GetMousePosition();

			virtual glm::vec2 GetMousePositionDifferential();

			void OnUpdate();

		private:
			void OnMouseButtonPressed(Buffalo::Shared<Events::Event> event);

			void OnMouseButtonReleased(Buffalo::Shared<Events::Event> event);

			void OnKeyPressed(Buffalo::Shared<Events::Event> event);

			void OnKeyReleased(Buffalo::Shared<Events::Event> event);

			void OnMouseMoved(Buffalo::Shared<Events::Event> event);

		private:
			Buffalo::Unique<Events::EventDispatcher> _eventDispatcher;

			GLFWwindow* _window;

			std::map<Key, bool> _keyStates; // TODO: Initialize with keys to eliminate the if check when writing to this.

			std::map<MouseCodes, bool> _mouseButtonStates; // TODO: Initialize with mouse codes to eliminate the if check when writing to this.

			glm::vec2 _mousePosition;

			glm::vec2 _mousePositionDifferential;
		};
	}
}