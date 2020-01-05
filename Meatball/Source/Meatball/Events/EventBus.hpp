#pragma once

#include <map>
#include <memory>
#include <set>
#include <Meatball/Events/Event.hpp>
#include <Meatball/Events/EventType.hpp>
#include <Meatball/Events/EventReceiver.hpp>
#include <Meatball/Core.hpp>

namespace Meatball {
	namespace Events {
		class EventBus {
		public:
            virtual ~EventBus() = default;

			void RemoveEventReceiver(EventReceiver* receiver);

			template<typename TEventType, typename ...TEventTypes>
			void AddEventReceiver(EventReceiver* receiver, TEventType type, TEventTypes... types) {
				AddEventReceiverForEventType(receiver, type);
				AddEventReceiver(receiver, types...);
			}

			void AddEventReceiver(EventReceiver* receiver, EventType type) {
				AddEventReceiverForEventType(receiver, type);
			}

			template<typename TEvent, typename ...TEventArgs>
			void Publish(TEventArgs... args) {
				PublishEvent(std::make_shared<TEvent>(args...));
			}

		protected:
			virtual void PublishEvent(Shared<Event> event);

		private:
			void AddEventReceiverForEventType(EventReceiver* receiver, EventType type);

		private:
			std::map<EventType, std::set<EventReceiver*>> receivers;
		};
	}
}

#define EVENT_BUS() Meatball::Events::EventBus::Get()