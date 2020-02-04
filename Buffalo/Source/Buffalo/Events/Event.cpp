#include <Buffalo/Events/Event.hpp>

namespace Buffalo {
	namespace Events {
		void Event::StopPropagation() {
			_handled = true;
		}
	}
}