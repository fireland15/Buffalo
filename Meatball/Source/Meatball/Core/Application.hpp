#pragma once

#include <Meatball/Core.hpp>

namespace Meatball {
	namespace Events {
		class Event;
		class EventBus;
		class EventDispatcher;
	}

	namespace Windowing {
		class Window;
	}

	class Application {
	public:
		Application();
		virtual ~Application();

		void Run();

	protected:

		inline Events::EventBus& GetEventBus();

		inline Events::EventDispatcher& GetEventDispatcher();

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