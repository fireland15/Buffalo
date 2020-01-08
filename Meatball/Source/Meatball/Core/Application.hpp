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

		inline Events::EventBus& GetEventBus() { return *_eventBus; }

		inline Events::EventDispatcher& GetEventDispatcher() { return *_eventDispatcher; }

	private:

		void OnWindowClosed(Shared<Events::Event> event);

	private:
		Unique<Events::EventBus> _eventBus;
		Unique<Events::EventDispatcher> _eventDispatcher;
		Unique<Windowing::Window> _window;
		bool running = true;
	};

    Unique<Application> CreateApplication();
}