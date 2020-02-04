#pragma once

#include <functional>
#include <map>
#include <Buffalo/Core.hpp>
#include <Buffalo/Events/EventType.hpp>
#include <Buffalo/Events/EventReceiver.hpp>

namespace Buffalo {
	namespace Events {
		class Event;
		class EventBus;

		class EventDispatcher {
		public:
			EventDispatcher(EventBus& bus);

			EventDispatcher& AddEventHandler(EventType type, std::function<void(Shared<Event>)> handler);

			void DispatchEvents();

			EventBus& GetEventBus();

		private:

			void Dispatch(Shared<Event> event);

		private:
			EventBus& _bus;
			EventReceiver _receiver;
			std::map<EventType, std::function<void(Shared<Event>)>> _handlers;
		};
	}
}