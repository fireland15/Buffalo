#pragma once

#include <map>
#include <set>
#include <Buffalo/Events/EventType.hpp>
#include <Buffalo/Core.hpp>
#include <Buffalo/Core/Debug.hpp>

namespace Buffalo {
	namespace Events {
		class Event;
		class EventDispatcher;
		class EventReceiver;

		class EventBus {
		public:
            virtual ~EventBus() = default;

			void RemoveEventReceiver(EventReceiver* receiver);

			void AddEventReceiver(EventReceiver* receiver, EventType type);

			template<typename TEvent, typename ...TEventArgs>
			void Publish(TEventArgs... args) {
				BUFFALO_PROFILE_FUNC();
				PublishEvent(std::make_shared<TEvent>(args...));
			}

			Unique<EventDispatcher> GetDispatcher();

		protected:
			virtual void PublishEvent(Shared<Event> event);

		private:
			std::map<EventType, std::set<EventReceiver*>> receivers;
		};
	}
}
