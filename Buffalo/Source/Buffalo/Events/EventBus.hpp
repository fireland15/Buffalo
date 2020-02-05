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
	}

	class EventBus {
	public:
        virtual ~EventBus() = default;

		static void RemoveEventReceiver(Events::EventReceiver* receiver);

		static void AddEventReceiver(Events::EventReceiver* receiver, Events::EventType type);

		template<typename TEvent, typename ...TEventArgs>
		static void Publish(TEventArgs... args) {
			BUFFALO_PROFILE_FUNC();
			_instance.PublishEvent(std::make_shared<TEvent>(args...));
		}

		static Unique<Events::EventDispatcher> GetDispatcher();

	protected:
		virtual void PublishEvent(Shared<Events::Event> event);

	private:
		std::map<Events::EventType, std::set<Events::EventReceiver*>> receivers;

		static EventBus _instance;
	};
}
