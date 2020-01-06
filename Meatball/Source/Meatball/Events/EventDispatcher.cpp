#include <Meatball/Events/EventDispatcher.hpp>
#include <Meatball/Events/Event.hpp>
#include <Meatball/Events/EventBus.hpp>
#include <Meatball/Core/Debug.hpp>

namespace Meatball {
	namespace Events {
		EventDispatcher::EventDispatcher(EventBus& bus) : _bus(bus) { }

		EventDispatcher& EventDispatcher::AddEventHandler(EventType type, std::function<void(Shared<Event>)> handler) {
			MEATBALL_PROFILE_FUNC();
			_bus.AddEventReceiver(&_receiver, type);
			_handlers[type] = handler;
			return *this;
		}

		void EventDispatcher::DispatchEvents() {
			MEATBALL_PROFILE_FUNC();
			while (!_receiver.Empty()) {
				Dispatch(_receiver.Pop());
			}
		}

		void EventDispatcher::Dispatch(Shared<Event> event) {
			MEATBALL_PROFILE_FUNC();
			auto type = event->GetType();
			_handlers[type](event);
		}

		EventBus& EventDispatcher::GetEventBus() {
			MEATBALL_PROFILE_FUNC();
			return _bus;
		}
	}
}