#pragma once

#include <functional>
#include <map>
#include <Buffalo/Core.hpp>
#include <Buffalo/Events/EventType.hpp>
#include <Buffalo/Events/EventReceiver.hpp>

namespace Buffalo {
	namespace Events {
		class Event;

		class EventDispatcher {
		public:
			EventDispatcher();

			EventDispatcher& AddEventHandler(EventType type, std::function<void(Shared<Event>)> handler);

			void DispatchEvents();

		private:

			void Dispatch(Shared<Event> event);

		private:
			EventReceiver _receiver;
			std::map<EventType, std::function<void(Shared<Event>)>> _handlers;
		};
	}
}