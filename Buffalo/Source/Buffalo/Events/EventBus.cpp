#include <Buffalo/Events/EventBus.hpp>
#include <Buffalo/Events/Event.hpp>
#include <Buffalo/Events/EventReceiver.hpp>
#include <Buffalo/Events/EventDispatcher.hpp>

namespace Buffalo {
	EventBus EventBus::_instance;

	void EventBus::PublishEvent(Shared<Events::Event> event) {
		BUFFALO_PROFILE_FUNC();
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

	void EventBus::RemoveEventReceiver(Events::EventReceiver* receiver) {
		BUFFALO_PROFILE_FUNC();
		for (auto& pair : _instance.receivers) {
			auto& receiversForType = pair.second;
			receiversForType.erase(receiver);
		}
	}

	void EventBus::AddEventReceiver(Events::EventReceiver* receiver, Events::EventType type) {
		BUFFALO_PROFILE_FUNC();
		if (_instance.receivers.count(type) == 0) {
			_instance.receivers.emplace(type, std::set<Events::EventReceiver*>());
		}
		_instance.receivers[type].emplace(std::ref(receiver));
	}

	Unique<Events::EventDispatcher> EventBus::GetDispatcher() {
		BUFFALO_PROFILE_FUNC();
		return std::make_unique<Events::EventDispatcher>();
	}
}