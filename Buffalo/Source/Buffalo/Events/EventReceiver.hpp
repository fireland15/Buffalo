#pragma once

#include <memory>
#include <queue>
#include <Buffalo/Core.hpp>
#include <Buffalo/Events/Event.hpp>

namespace Buffalo {
	namespace Events {
		class EventReceiver {
		public:
			bool Empty();

			Shared<Event> Pop();

			void Push(Shared<Event> event);

		private:
			std::queue<Shared<Event>> eventQueue;
		};
	}
}