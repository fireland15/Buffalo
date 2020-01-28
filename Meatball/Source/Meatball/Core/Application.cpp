#include <Meatball/Core/Application.hpp>
#include <Meatball/Core/Debug.hpp>
#include <Meatball/Events/ApplicationEvent.hpp>
#include <Meatball/Events/EventDispatcher.hpp>
#include <Meatball/Events/EventBus.hpp>
#include <Meatball/Windowing/Window.hpp>
#include <Platform/Glfw/GlfwWindow.hpp>

#include <iostream>

namespace Meatball {
    Application::Application()
		: _eventBus(std::make_unique<Events::EventBus>()), _window(std::make_unique<Windowing::GlfwWindow>(this->_eventBus->GetDispatcher())), _eventDispatcher(this->_eventBus->GetDispatcher()) {
		GetEventDispatcher().AddEventHandler(Events::EventType::WindowClosed, MEATBALL_BIND_EVENT_HANDLER(Application::OnWindowClosed));
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
		MEATBALL_PROFILE_FUNC();

		while (running) {
			GetEventDispatcher().DispatchEvents();
			this->OnUpdate();
			_window->OnUpdate();
		}

		_window->Terminate();
    }

	void Application::OnWindowClosed(Shared<Events::Event> event) {
		MEATBALL_LOG_INFO("Application stopping.");
		running = false;
	}
}