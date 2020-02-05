#include <Buffalo/Core/Application.hpp>
#include <Buffalo/Core/Debug.hpp>
#include <Buffalo/Events/ApplicationEvent.hpp>
#include <Buffalo/Events/EventDispatcher.hpp>
#include <Buffalo/Events/EventBus.hpp>
#include <Buffalo/Windowing/Window.hpp>
#include <Platform/Glfw/GlfwWindow.hpp>

#include <iostream>

namespace Buffalo {
    Application::Application()
		: _eventDispatcher(EventBus::GetDispatcher())
		, _window(std::make_unique<Windowing::GlfwWindow>(EventBus::GetDispatcher())) {
		GetEventDispatcher().AddEventHandler(Events::EventType::WindowClosed, BUFFALO_BIND_EVENT_HANDLER(Application::OnWindowClosed));
    }

    Application::~Application() {

    }

	Events::EventDispatcher& Application::GetEventDispatcher() {
		return *_eventDispatcher;
	}

	void Application::OnUpdate() {

	}

    void Application::Run() {
		BUFFALO_PROFILE_FUNC();

		while (running) {
			GetEventDispatcher().DispatchEvents();
			this->OnUpdate();
			_window->OnUpdate();
		}

		_window->Terminate();
    }

	void Application::OnWindowClosed(Shared<Events::Event> event) {
		BUFFALO_LOG_INFO("Application stopping.");
		running = false;
	}
}