#include <Meatball/Core/Application.hpp>
#include <Meatball/Core/Debug.hpp>
#include <Meatball/Events/ApplicationEvent.hpp>

#include <iostream>

namespace Meatball {
    Application::Application(Unique<Events::EventBus> eventBus, Unique<Windowing::Window> window)
		: _eventBus(std::move(eventBus)), _window(std::move(window)), _eventDispatcher(this->_eventBus->GetDispatcher()) {
		GetEventDispatcher().AddEventHandler(Events::EventType::WindowClosed, MEATBALL_BIND_EVENT_HANDLER(Application::OnWindowClosed));
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

		while (running) {
			GetEventDispatcher().DispatchEvents();
			_window->OnUpdate();
			MEATBALL_PROFILE_SCOPE("Main Loop");
			MEATBALL_LOG_TRACE("Beginning Frame");
			MEATBALL_LOG_TRACE("Completed Frame");
		}

		MEATBALL_LOG_TRACE("Exiting Application::Run()");
    }

	void Application::OnWindowClosed(Shared<Events::Event> event) {
		running = false;
	}
}