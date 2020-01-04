#pragma once

#include <iostream>
#include <Meatball/Core/Application.hpp>
#include <Meatball/Events/EventReceiver.hpp>

class PlaygroundApplication : public Meatball::Application {
public:
	PlaygroundApplication(Meatball::Unique<Meatball::Events::EventBus> eventBus);
	virtual ~PlaygroundApplication();

private:
	Meatball::Events::EventReceiver eventReceiver;
};