#include <PlaygroundApplication.hpp>

#include <iostream>
#include <Meatball/Events/EventBus.hpp>

using EventType = Meatball::Events::EventType;

PlaygroundApplication::PlaygroundApplication() {
	GetEventBus().AddEventReceiver(&eventReceiver, EventType::Test);
	GetEventBus().Publish(std::make_shared<Meatball::Events::Event>(Meatball::Events::EventType::Test));
}

PlaygroundApplication::~PlaygroundApplication() {
	auto event = eventReceiver.Pop();
	std::cout << (int)event->GetType() << std::endl;
	GetEventBus().RemoveEventReceiver(&eventReceiver);
}

Meatball::Application* Meatball::CreateApplication() {
	return new PlaygroundApplication();
}