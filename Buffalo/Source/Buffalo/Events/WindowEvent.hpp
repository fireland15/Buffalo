#pragma once

#include <Buffalo/Events/Event.hpp>

namespace Buffalo {
	namespace Events {
		class WindowClosedEvent : public Event {
		public:
			virtual ~WindowClosedEvent() = default;

			virtual inline EventType GetType() { return type; }

			virtual inline const char* GetName() { return "WindowClosedEvent"; }

		private:
			const static EventType type = EventType::WindowClosed;
		};
    }
}