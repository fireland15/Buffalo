#include <Buffalo/Events/EventDispatcher.hpp>
#include <Buffalo/Events/Event.hpp>
#include <Buffalo/Events/EventBus.hpp>
#include <Buffalo/Core/Debug.hpp>

namespace Buffalo {
	namespace Events {
		EventDispatcher::EventDispatcher(EventBus& bus) : _bus(bus) { }

		EventDispatcher& EventDispatcher::AddEventHandler(EventType type, std::function<void(Shared<Event>)> handler) {
			BUFFALO_PROFILE_FUNC();
			_bus.AddEventReceiver(&_receiver, type);
			_handlers[type] = handler;
			return *this;
		}

		void EventDispatcher::DispatchEvents() {
			BUFFALO_PROFILE_FUNC();
			while (!_receiver.Empty()) {
				Dispatch(_receiver.Pop());
			}
		}

		void EventDispatcher::Dispatch(Shared<Event> event) {
			BUFFALO_PROFILE_FUNC();
			auto type = event->GetType();
			_handlers[type](event);
		}

		EventBus& EventDispatcher::GetEventBus() {
			BUFFALO_PROFILE_FUNC();
			return _bus;
		}
	}
}