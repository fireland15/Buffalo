#pragma once

#include <Buffalo/Events/Event.hpp>

namespace Buffalo {
	namespace Events {
		class ApplicationTickEvent : public Event {
		public:
			virtual ~ApplicationTickEvent() = default;

			virtual inline EventType GetType() { return type; }

			virtual inline const char* GetName() { return "ApplicationTickEvent"; }

		private:
			const static EventType type = EventType::ApplicationTick;
		};

		class ApplicationShutdownEvent : public Event {
		public:
			virtual ~ApplicationShutdownEvent() = default;

			virtual inline EventType GetType() { return type; }

			virtual inline const char* GetName() { return "ApplicationShutdownEvent"; }

		private:
			const static EventType type = EventType::ApplicationShutdown;
		};
	}
}