#include <Meatball/Events/EventReceiver.hpp>
#include <Meatball/Core/Debug.hpp>

namespace Meatball {
	namespace Events {
		bool EventReceiver::Empty() {
			MEATBALL_PROFILE_FUNC();
			return eventQueue.empty();
		}

		std::shared_ptr<Event> EventReceiver::Pop() {
			MEATBALL_PROFILE_FUNC();
			auto event = eventQueue.front();
			eventQueue.pop();
			return event;
		}

		void EventReceiver::Push(std::shared_ptr<Event> event) {
			MEATBALL_PROFILE_FUNC();
			eventQueue.push(event);
		}
	}
}