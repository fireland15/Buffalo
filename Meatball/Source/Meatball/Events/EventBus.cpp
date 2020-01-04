#include <Meatball/Events/EventBus.hpp>

namespace Meatball {
	namespace Events {
		static EventBus eventBus;

		void EventBus::Publish(std::shared_ptr<Event> event) {
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
			for (auto& pair : receivers) {
				auto& receiversForType = pair.second;
				receiversForType.erase(receiver);
			}
		}

		void EventBus::AddEventReceiverForEventType(EventReceiver* receiver, EventType type) {
			if (receivers.count(type) == 0) {
				receivers.emplace(type, std::set<EventReceiver*>());
			}
			receivers[type].emplace(std::ref(receiver));
		}
	}
}