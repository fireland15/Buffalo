#pragma once

#include <Meatball/Events/EventBus.hpp>
#include <Meatball/Core.hpp>
#include <Meatball/Windowing/Window.hpp>

namespace Meatball {
	class Application {
	public:
		Application(Unique<Events::EventBus> eventBus, Unique<Windowing::Window> window);
		virtual ~Application();

		void Run();

	protected:
		inline Events::EventBus& GetEventBus() { return *eventBus; }

	private:

		void OnWindowClosed(Shared<Events::Event> event);

	private:
		Unique<Events::EventBus> eventBus;
		Unique<Events::EventDispatcher> eventDispatcher;
		Unique<Windowing::Window> window;
		bool running = true;
	};

    Unique<Application> CreateApplication();
}