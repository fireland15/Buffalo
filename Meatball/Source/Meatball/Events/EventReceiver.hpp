#pragma once

#include <memory>
#include <queue>
#include <Meatball/Events/Event.hpp>

namespace Meatball {
	namespace Events {
		class EventReceiver {
		public:
			std::shared_ptr<Event> Pop();
			void Push(std::shared_ptr<Event> event);

		private:
			std::queue<std::shared_ptr<Event>> eventQueue;
		};
	}
}