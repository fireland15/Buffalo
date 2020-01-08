#include <Meatball/Windowing/GlfwWindow.hpp>
#include <sstream>
#include <GLFW/glfw3.h>
#include <Meatball/Core/Debug.hpp>
#include <Meatball/Core/Keys.hpp>
#include <Meatball/Events/EventBus.hpp>
#include <Meatball/Events/WindowEvent.hpp>
#include <Meatball/Events/KeyEvent.hpp>

namespace Meatball {
	namespace Windowing {
		int GlfwWindow::_glfwWindowCount = 0;

		void glfwErrorCallback(int error, const char* description);

		//////////////////////////////////////
		// Constructor(s) / Destructor
		//////////////////////////////////////

		GlfwWindow::GlfwWindow(Unique<Events::EventDispatcher> eventDispatcher, const WindowProps & windowProps)
			: Window(std::move(eventDispatcher)) {
			MEATBALL_PROFILE_FUNC();
			if (_glfwWindowCount == 0) {
				glfwSetErrorCallback(glfwErrorCallback);
				MEATBALL_LOG_INFO("Initializing GLFW.");
				int glfwInitResult = glfwInit();
				if (!glfwInitResult) {
					MEATBALL_LOG_ERROR("Failed to initialize GLFW!");
					throw std::runtime_error("Failed to initialize GLFW!");
				}
			}

			GetEventDispatcher()
				.AddEventHandler(Events::EventType::ApplicationShutdown, MEATBALL_BIND_EVENT_HANDLER(GlfwWindow::OnApplicationShutdown));

			MEATBALL_LOG_INFO("Creating GLFW Window.");
			_glfwWindow = glfwCreateWindow(windowProps.Width, windowProps.Height, windowProps.Title, nullptr, nullptr);
			if (_glfwWindow == nullptr) {
				MEATBALL_LOG_ERROR("Failed to create a GLFW window!");
				throw std::runtime_error("Failed to create a GLFW window!");
			}

			glfwSetWindowUserPointer(_glfwWindow, static_cast<void*>(this));
			glfwSetWindowCloseCallback(_glfwWindow, &GlfwWindow::glfwWindowCloseCallback);
			glfwSetKeyCallback(_glfwWindow, &GlfwWindow::glfwKeyCallback);
		}

		GlfwWindow::~GlfwWindow() {
			MEATBALL_PROFILE_FUNC();
			if (_glfwWindowCount-- == 0) {
				glfwTerminate();
			}
		}

		//////////////////////////////////////
		// Lifetime Methods
		//////////////////////////////////////

		void GlfwWindow::OnUpdate() {
			MEATBALL_PROFILE_FUNC();
			glfwSwapBuffers(_glfwWindow);
			glfwPollEvents();
		}

		//////////////////////////////////////
		// Event Handlers
		//////////////////////////////////////

		void GlfwWindow::OnApplicationShutdown(Shared<Events::Event> event) {
			MEATBALL_PROFILE_FUNC();
			glfwDestroyWindow(_glfwWindow);
		}

		//////////////////////////////////////
		// GLFW Callback Handlers
		//////////////////////////////////////

		void GlfwWindow::HandleWindowClosed() {
			MEATBALL_PROFILE_FUNC();
			GetEventBus().Publish<Events::WindowClosedEvent>();
		}

		void GlfwWindow::HandleKeyEvent(int key, int scancode, int action, int mods) {
			MEATBALL_PROFILE_FUNC();
			switch (action) {
			case GLFW_RELEASE:
				GetEventBus().Publish<Events::KeyReleasedEvent>(static_cast<Key>(key));
			case GLFW_PRESS:
				GetEventBus().Publish<Events::KeyPressedEvent>(static_cast<Key>(key));
			case GLFW_REPEAT:
			default:
				return;
			}
		}

		//////////////////////////////////////
		// Static Methods
		//////////////////////////////////////

		void GlfwWindow::glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			MEATBALL_PROFILE_FUNC();
			GlfwWindow* meatballWindow = static_cast<GlfwWindow*>(glfwGetWindowUserPointer(window));
			meatballWindow->HandleKeyEvent(key, scancode, action, mods);
		}

		void GlfwWindow::glfwWindowCloseCallback(GLFWwindow* window) {
			MEATBALL_PROFILE_FUNC();
			GlfwWindow* meatballWindow = static_cast<GlfwWindow*>(glfwGetWindowUserPointer(window));
			meatballWindow->HandleWindowClosed();
		}

		void glfwErrorCallback(int error, const char* description) {
			std::stringstream ss;
			ss << "GLFW error '" << error << "'. " << description;
			MEATBALL_LOG_ERROR(ss.str());
		}
	}
}