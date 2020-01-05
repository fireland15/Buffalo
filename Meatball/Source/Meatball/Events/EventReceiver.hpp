#pragma once

#include <memory>
#include <queue>
#include <Meatball/Core.hpp>
#include <Meatball/Events/Event.hpp>

namespace Meatball {
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