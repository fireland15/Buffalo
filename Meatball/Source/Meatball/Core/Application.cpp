#include <Meatball/Core/Application.hpp>
#include <Meatball/Core/Debug.hpp>
#include <Meatball/Events/ApplicationEvent.hpp>

#include <iostream>

namespace Meatball {
    Application::Application(Unique<Events::EventBus> eventBus, Unique<Windowing::Window> window)
		: eventBus(std::move(eventBus)), window(std::move(window)) {
		MEATBALL_LOG_TRACE("Entered Application::Application()");
		MEATBALL_LOG_TRACE("Exiting Application::Application()");
    }

    Application::~Application() {
		MEATBALL_LOG_TRACE("Entered Application::~Application()");
		MEATBALL_LOG_TRACE("Exiting Application::~Application()");
    }

    void Application::Run() {
		MEATBALL_LOG_TRACE("Entered Application::Run()");
		MEATBALL_PROFILE_FUNC();

		int x = 10000;
		while (x-- > 0) {
			window->OnUpdate();
			MEATBALL_PROFILE_SCOPE("Main Loop");
			MEATBALL_LOG_TRACE("Beginning Frame");
			if (x == 7777) {
				GetEventBus().Publish<Events::ApplicationShutdownEvent>();
			}
			MEATBALL_LOG_TRACE("Completed Frame");
		}

		MEATBALL_LOG_TRACE("Exiting Application::Run()");
    }
}