#pragma once

#include <Meatball/Events/EventType.hpp>

namespace Meatball {
	namespace Events {
		class Event {
		public:
			Event(EventType type);

			virtual ~Event() = default;

			EventType GetType();

		private:
			EventType type;
		};
	}
}