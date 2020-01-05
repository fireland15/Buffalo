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
		Unique<Events::EventBus> eventBus;
		Unique<Windowing::Window> window;
	};

    Unique<Application> CreateApplication();
}