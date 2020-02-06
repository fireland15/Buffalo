#pragma once

#include <Buffalo/Events/Event.hpp>
#include <Buffalo/Core/MouseCodes.hpp>

namespace Buffalo {
	namespace Events {
		class MouseMovedEvent : public Event {
		public:

			MouseMovedEvent(double xpos, double ypos) : _xpos(xpos), _ypos(ypos) { }

			virtual ~MouseMovedEvent() = default;

			virtual EventType GetType() { return EventType::MouseMoved; }

			virtual const char* GetName() { return "MouseMoved"; }

			inline glm::vec2 GetPosition() { return { _xpos, _ypos }; }

		private:

			double _xpos;

			double _ypos;

		};

		class MouseButtonEvent : public Event {
		public:

			MouseButtonEvent(MouseCodes mouseCode) : _mouseCode(mouseCode) { }

			virtual ~MouseButtonEvent() = default;

		private:

			MouseCodes _mouseCode;
		};

		class MouseButtonPressedEvent : public MouseButtonEvent {
		public:

			MouseButtonPressedEvent(MouseCodes mouseCode) : MouseButtonEvent(mouseCode) { }

			virtual EventType GetType() { return EventType::MouseButtonPressed; }

			virtual const char* GetName() { return "MouseButtonPressed"; }

		};

		class MouseButtonReleasedEvent : public MouseButtonEvent {
		public:

			MouseButtonReleasedEvent(MouseCodes mouseCode) : MouseButtonEvent(mouseCode) { }

			virtual EventType GetType() { return EventType::MouseButtonReleased; }

			virtual const char* GetName() { return "MouseButtonReleased"; }

		};
	}
}