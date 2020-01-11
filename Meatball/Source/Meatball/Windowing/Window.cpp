#include <Meatball/Windowing/Window.hpp>
#include <Meatball/Events/EventDispatcher.hpp>
#include <Meatball/Events/EventBus.hpp>

namespace Meatball {
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