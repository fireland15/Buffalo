#pragma once

#include <functional>
#include <map>
#include <Meatball/Core.hpp>
#include <Meatball/Events/EventType.hpp>
#include <Meatball/Events/EventReceiver.hpp>

namespace Meatball {
	namespace Events {
		class Event;
		class EventBus;

		class EventDispatcher {
		public:
			EventDispatcher(EventBus& bus);

			EventDispatcher& AddEventHandler(EventType type, std::function<void(Shared<Event>)> handler);

			void DispatchEvents();

		private:

			void Dispatch(Shared<Event> event);

		private:
			EventBus& _bus;
			EventReceiver _receiver;
			std::map<EventType, std::function<void(Shared<Event>)>> _handlers;
		};
	}
}