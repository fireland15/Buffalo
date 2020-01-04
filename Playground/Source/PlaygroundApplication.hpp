#pragma once

#include <iostream>
#include <Meatball/Core/Application.hpp>
#include <Meatball/Events/EventReceiver.hpp>

class PlaygroundApplication : public Meatball::Application {
public:
	PlaygroundApplication();
	virtual ~PlaygroundApplication();

private:
	Meatball::Events::EventReceiver eventReceiver;
};