#include <Buffalo/Windowing/Window.hpp>
#include <Buffalo/Events/EventDispatcher.hpp>
#include <Buffalo/Events/EventBus.hpp>

namespace Buffalo {
	namespace Windowing {

		Window::Window(Unique<Events::EventDispatcher> eventDispatcher)
			: _eventDispatcher(std::move(eventDispatcher)) {
		}

		Events::EventDispatcher& Window::GetEventDispatcher() { 
			return *_eventDispatcher; 
		}

		Events::EventBus& Window::GetEventBus() { 
			return _eventDispatcher->GetEventBus(); 
		}

	}
}