#pragma once

#include <map>
#include <memory>
#include <set>
#include <Meatball/Events/Event.hpp>
#include <Meatball/Events/EventType.hpp>
#include <Meatball/Events/EventReceiver.hpp>

namespace Meatball {
	namespace Events {
		class EventBus {
		public:
			void RemoveEventReceiver(EventReceiver* receiver);

			template<typename TEventType, typename ...TEventTypes>
			void AddEventReceiver(EventReceiver* receiver, TEventType type, TEventTypes... types) {
				AddEventReceiverForEventType(receiver, type);
				AddEventReceiver(receiver, types...);
			}

			void AddEventReceiver(EventReceiver* receiver, EventType type) {
				AddEventReceiverForEventType(receiver, type);
			}

			void Publish(std::shared_ptr<Event> event);

		private:
			void AddEventReceiverForEventType(EventReceiver* receiver, EventType type);

		private:
			std::map<EventType, std::set<EventReceiver*>> receivers;
		};
	}
}

#define EVENT_BUS() Meatball::Events::EventBus::Get()