#pragma once

#include <Meatball/Core.hpp>
#include <Meatball/Windowing/Window.hpp>

struct GLFWwindow;

namespace Meatball {
	namespace Events {
		class EventDispatcher;
	}

	namespace Windowing {
		class GlfwWindow : public Window {
		public:
			GlfwWindow(Unique<Events::EventDispatcher> eventDispatcher, const WindowProps & = WindowProps());

			virtual ~GlfwWindow() = default;

			virtual void OnUpdate();

			void OnApplicationShutdown(Shared<Events::Event> event);

		private:

			static void glfwWindowCloseCallback(GLFWwindow* window);

		private:
			GLFWwindow* glfwWindow;
		};
	}
}