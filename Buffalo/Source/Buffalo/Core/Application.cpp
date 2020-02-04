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
		: _eventBus(std::make_unique<Events::EventBus>()), _window(std::make_unique<Windowing::GlfwWindow>(this->_eventBus->GetDispatcher())), _eventDispatcher(this->_eventBus->GetDispatcher()) {
		GetEventDispatcher().AddEventHandler(Events::EventType::WindowClosed, BUFFALO_BIND_EVENT_HANDLER(Application::OnWindowClosed));
    }

    Application::~Application() {

    }

	Events::EventBus& Application::GetEventBus() {
		return *_eventBus; 
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