#pragma once

#include <Buffalo/Core.hpp>

namespace Buffalo {
	namespace Events {
		class Event;
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
		
		inline Events::EventDispatcher& GetEventDispatcher();

		virtual void OnUpdate();

	private:

		void OnWindowClosed(Shared<Events::Event> event);

	private:
		Unique<Events::EventDispatcher> _eventDispatcher;
		Unique<Windowing::Window> _window;
		bool running = true;
	};

    Unique<Application> CreateApplication();
}