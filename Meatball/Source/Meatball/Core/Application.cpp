#include <Meatball/Core/Application.hpp>
#include <Meatball/Core/Debug.hpp>
#include <Meatball/Events/ApplicationEvent.hpp>

#include <iostream>

namespace Meatball {
    Application::Application(Unique<Events::EventBus> eventBus, Unique<Windowing::Window> window)
		: _eventBus(std::move(eventBus)), _window(std::move(window)), _eventDispatcher(this->_eventBus->GetDispatcher()) {
		GetEventDispatcher().AddEventHandler(Events::EventType::WindowClosed, MEATBALL_BIND_EVENT_HANDLER(Application::OnWindowClosed));
    }

    Application::~Application() {
    }

    void Application::Run() {
		MEATBALL_PROFILE_FUNC();

		while (running) {
			MEATBALL_PROFILE_SCOPE("Main Loop");
			GetEventDispatcher().DispatchEvents();
			_window->OnUpdate();
		}
    }

	void Application::OnWindowClosed(Shared<Events::Event> event) {
		MEATBALL_LOG_INFO("Application stopping.");
		running = false;
	}
}