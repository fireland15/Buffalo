#include <Buffalo/Events/EventReceiver.hpp>
#include <Buffalo/Core/Debug.hpp>

namespace Buffalo {
	namespace Events {
		bool EventReceiver::Empty() {
			BUFFALO_PROFILE_FUNC();
			return eventQueue.empty();
		}

		std::shared_ptr<Event> EventReceiver::Pop() {
			BUFFALO_PROFILE_FUNC();
			auto event = eventQueue.front();
			eventQueue.pop();
			return event;
		}

		void EventReceiver::Push(std::shared_ptr<Event> event) {
			BUFFALO_PROFILE_FUNC();
			eventQueue.push(event);
		}
	}
}