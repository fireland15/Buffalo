#include <PlaygroundApplication.hpp>

#include <iostream>
#include <Meatball/Core.hpp>
#include <Meatball/Core/ApplicationBuilder.hpp>
#include <Platform/Glfw/GlfwWindow.hpp>

using EventType = Meatball::Events::EventType;

PlaygroundApplication::PlaygroundApplication(Meatball::Unique<Meatball::Events::EventBus> eventBus)
		: Application(std::move(eventBus), std::make_unique<Meatball::Windowing::GlfwWindow>(eventBus->GetDispatcher())) {

}

PlaygroundApplication::~PlaygroundApplication() {
}

Meatball::Unique<Meatball::Application> Meatball::CreateApplication() {
	Meatball::ApplicationBuilder appBuilder;
	return appBuilder.AddEventBus<Events::EventBus>().Build<PlaygroundApplication>();
}