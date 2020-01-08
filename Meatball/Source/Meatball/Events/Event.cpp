#include <Meatball/Events/Event.hpp>

namespace Meatball {
	namespace Events {
		void Event::StopPropagation() {
			_handled = true;
		}
	}
}