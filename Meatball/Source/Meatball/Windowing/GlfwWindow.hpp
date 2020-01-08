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

			virtual ~GlfwWindow();

			virtual void OnUpdate();

			void OnApplicationShutdown(Shared<Events::Event> event);

			void HandleWindowClosed();

			void HandleKeyEvent(int key, int scancode, int action, int mods);

		private:

			static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

			static void glfwWindowCloseCallback(GLFWwindow* window);

		private:
			GLFWwindow* _glfwWindow;

			static int _glfwWindowCount;
		};
	}
}