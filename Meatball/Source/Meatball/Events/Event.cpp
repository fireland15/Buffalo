#include <Meatball/Events/Event.hpp>

namespace Meatball {
	namespace Events {
		Event::Event(EventType type) : type(type) { }

		EventType Event::GetType() {
			return type;
		}
	}
}