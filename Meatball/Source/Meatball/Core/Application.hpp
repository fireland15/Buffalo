#pragma once

#include <Meatball/Events/EventBus.hpp>

namespace Meatball {
	class Application {
	public:
		Application();
		virtual ~Application();

		void Run();

	protected:
		inline Events::EventBus& GetEventBus() { return eventBus; }

	private:
		Events::EventBus eventBus;
	};

    Application* CreateApplication();
}