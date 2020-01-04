#include <Meatball/Events/Event.hpp>

namespace Meatball {
	namespace Events {
		void Event::StopPropagation() {
			handled = true;
		}
	}
}