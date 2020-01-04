#include <Meatball/Events/EventReceiver.hpp>

namespace Meatball {
	namespace Events {
		std::shared_ptr<Event> EventReceiver::Pop() {
			auto event = eventQueue.front();
			eventQueue.pop();
			return event;
		}

		void EventReceiver::Push(std::shared_ptr<Event> event) {
			eventQueue.push(event);
		}
	}
}