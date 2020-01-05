#pragma once

#include <map>
#include <memory>
#include <set>
#include <Meatball/Events/Event.hpp>
#include <Meatball/Events/EventType.hpp>
#include <Meatball/Events/EventReceiver.hpp>
#include <Meatball/Events/EventDispatcher.hpp>
#include <Meatball/Core.hpp>
#include <Meatball/Core/Debug.hpp>

namespace Meatball {
	namespace Events {
		class EventDispatcher;

		class EventBus {
		public:
            virtual ~EventBus() = default;

			void RemoveEventReceiver(EventReceiver* receiver);

			void AddEventReceiver(EventReceiver* receiver, EventType type) {
				MEATBALL_PROFILE_FUNC();
				AddEventReceiverForEventType(receiver, type);
			}

			template<typename TEvent, typename ...TEventArgs>
			void Publish(TEventArgs... args) {
				MEATBALL_PROFILE_FUNC();
				PublishEvent(std::make_shared<TEvent>(args...));
			}

			Unique<EventDispatcher> GetDispatcher() {
				MEATBALL_PROFILE_FUNC();
				return std::make_unique<EventDispatcher>(*this);
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
