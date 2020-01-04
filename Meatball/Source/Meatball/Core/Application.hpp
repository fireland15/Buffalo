#pragma once

#include <Meatball/Events/EventBus.hpp>
#include <Meatball/Core.hpp>

namespace Meatball {
	class Application {
	public:
		Application(Unique<Events::EventBus> eventBus);
		virtual ~Application();

		void Run();

	protected:
		inline Events::EventBus& GetEventBus() { return *eventBus; }

	private:
		Unique<Events::EventBus> eventBus;
	};

    Unique<Application> CreateApplication();
}