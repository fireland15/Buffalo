#include <Meatball/Windowing/GlfwWindow.hpp>
#include <GLFW/glfw3.h>
#include <Meatball/Events/EventBus.hpp>
#include <Meatball/Events/WindowEvent.hpp>

namespace Meatball {
	namespace Windowing {
		GlfwWindow::GlfwWindow(Unique<Events::EventDispatcher> eventDispatcher, const WindowProps & windowProps)
			: Window(std::move(eventDispatcher)) {

			GetEventDispatcher()
				.AddEventHandler(Events::EventType::ApplicationShutdown, MEATBALL_BIND_EVENT_HANDLER(GlfwWindow::OnApplicationShutdown));

			glfwInit();
			glfwWindow = glfwCreateWindow(windowProps.Width, windowProps.Height, windowProps.Title, nullptr, nullptr);

			glfwSetWindowUserPointer(glfwWindow, static_cast<void*>(this));

			glfwSetWindowCloseCallback(glfwWindow, &GlfwWindow::glfwWindowCloseCallback);
		}

		void GlfwWindow::OnUpdate() {
			glfwSwapBuffers(glfwWindow);
			glfwPollEvents();
		}

		void GlfwWindow::OnApplicationShutdown(Shared<Events::Event> event) {
			glfwDestroyWindow(glfwWindow);
		}

		void GlfwWindow::glfwWindowCloseCallback(GLFWwindow* window) {
			GlfwWindow* meatballWindow = static_cast<GlfwWindow*>(glfwGetWindowUserPointer(window));
			meatballWindow->GetEventBus().Publish<Events::WindowClosedEvent>();
		}
	}
}