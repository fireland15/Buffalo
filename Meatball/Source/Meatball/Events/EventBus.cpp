#include <Meatball/Events/EventBus.hpp>

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

		void EventBus::AddEventReceiverForEventType(EventReceiver* receiver, EventType type) {
			MEATBALL_PROFILE_FUNC();
			if (receivers.count(type) == 0) {
				receivers.emplace(type, std::set<EventReceiver*>());
			}
			receivers[type].emplace(std::ref(receiver));
		}
	}
}