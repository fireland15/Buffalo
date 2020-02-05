#include <Buffalo/Windowing/Window.hpp>
#include <Buffalo/Events/EventDispatcher.hpp>

namespace Buffalo {
	namespace Windowing {

		Window::Window(Unique<Events::EventDispatcher> eventDispatcher)
			: _eventDispatcher(std::move(eventDispatcher)) {
		}

		Events::EventDispatcher& Window::GetEventDispatcher() { 
			return *_eventDispatcher; 
		}

	}
}