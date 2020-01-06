#include <Meatball/Events/EventBus.hpp>
#include <Meatball/Events/Event.hpp>
#include <Meatball/Events/EventReceiver.hpp>
#include <Meatball/Events/EventDispatcher.hpp>

namespace Meatball {
	namespace Events {
		void EventBus::PublishEvent(Shared<Event> event) {
			MEATBALL_PROFILE_FUNC();
			if (!event) {
				return;
			}
			auto type = event->GetType();
			auto receiversForTypeFindResult = receivers.find(type);
			if (receiversForTypeFindResult == receivers.end()) {
				return;
			}
			auto& receiversForType = receiversForTypeFindResult->second;
			for (auto receiver : receiversForType) {
				receiver->Push(event);
			}
		}

		void EventBus::RemoveEventReceiver(EventReceiver* receiver) {
			MEATBALL_PROFILE_FUNC();
			for (auto& pair : receivers) {
				auto& receiversForType = pair.second;
				receiversForType.erase(receiver);
			}
		}

		void EventBus::AddEventReceiver(EventReceiver* receiver, EventType type) {
			MEATBALL_PROFILE_FUNC();
			if (receivers.count(type) == 0) {
				receivers.emplace(type, std::set<EventReceiver*>());
			}
			receivers[type].emplace(std::ref(receiver));
		}

		Unique<EventDispatcher> EventBus::GetDispatcher() {
			MEATBALL_PROFILE_FUNC();
			return std::make_unique<EventDispatcher>(*this);
		}
	}
}