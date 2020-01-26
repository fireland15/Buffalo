#include <Platform/Glfw/GlfwWindow.hpp>
#include <sstream>
#include <GLFW/glfw3.h>
#include <Meatball/Core/Debug.hpp>
#include <Meatball/Core/Keys.hpp>
#include <Meatball/Events/EventBus.hpp>
#include <Meatball/Events/WindowEvent.hpp>
#include <Meatball/Events/KeyEvent.hpp>
#include <Meatball/Events/MouseEvent.hpp>
#include <Platform/OpenGL/OpenGLGraphicsContext.hpp>
#include <Meatball/Events/EventDispatcher.hpp>

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

			_context = std::make_unique<OpenGL::OpenGLGraphicsContext>(_glfwWindow);
			_context->Init();

			glfwSetWindowUserPointer(_glfwWindow, static_cast<void*>(this));
			glfwSetWindowCloseCallback(_glfwWindow, &GlfwWindow::glfwWindowCloseCallback);
			glfwSetKeyCallback(_glfwWindow, &GlfwWindow::glfwKeyCallback);
			glfwSetCursorPosCallback(_glfwWindow, &GlfwWindow::glfwCursorPosCallback);
			glfwSetMouseButtonCallback(_glfwWindow, &GlfwWindow::glfwMouseButtonCallback);
		}

		GlfwWindow::~GlfwWindow() {
			MEATBALL_PROFILE_FUNC();
			if (_glfwWindowCount-- == 0) {
				MEATBALL_LOG_INFO("Terminating GLFW.");
				glfwTerminate();
			}
		}

		//////////////////////////////////////
		// Lifetime Methods
		//////////////////////////////////////

		void GlfwWindow::OnUpdate() {
			MEATBALL_PROFILE_FUNC();
			_context->SwapBuffers();
			glfwPollEvents();
		}

		void GlfwWindow::Terminate() {
			MEATBALL_PROFILE_FUNC();
			MEATBALL_LOG_INFO("Closing Window.");
			glfwDestroyWindow(_glfwWindow);
			_glfwWindow == nullptr;
		}

		//////////////////////////////////////
		// Event Handlers
		//////////////////////////////////////

		void GlfwWindow::OnApplicationShutdown(Shared<Events::Event> event) {
			MEATBALL_PROFILE_FUNC();
			MEATBALL_LOG_INFO("Closing Window.");
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
				return;
			case GLFW_PRESS:
				GetEventBus().Publish<Events::KeyPressedEvent>(static_cast<Key>(key));
				return;
			case GLFW_REPEAT:
			default:
				return;
			}
		}

		void GlfwWindow::HandleCursorPosEvent(double xpos, double ypos) {
			MEATBALL_PROFILE_FUNC();
			GetEventBus().Publish<Events::MouseMovedEvent>(xpos, ypos);
		}

		void GlfwWindow::HandleMouseButtonEvent(int button, int action, int mods) {
			MEATBALL_PROFILE_FUNC();
			switch (action) {
			case GLFW_PRESS:
				GetEventBus().Publish<Events::MouseButtonPressedEvent>(static_cast<MouseCodes>(button));
				return;
			case GLFW_RELEASE:
				GetEventBus().Publish<Events::MouseButtonReleasedEvent>(static_cast<MouseCodes>(button));
				return;
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

		void GlfwWindow::glfwCursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
			MEATBALL_PROFILE_FUNC();
			GlfwWindow* meatballWindow = static_cast<GlfwWindow*>(glfwGetWindowUserPointer(window));
			meatballWindow->HandleCursorPosEvent(xpos, ypos);
		}

		void GlfwWindow::glfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
			MEATBALL_PROFILE_FUNC();
			GlfwWindow* meatballWindow = static_cast<GlfwWindow*>(glfwGetWindowUserPointer(window));
			meatballWindow->HandleMouseButtonEvent(button, action, mods);
		}

		void glfwErrorCallback(int error, const char* description) {
			std::stringstream ss;
			ss << "GLFW error '" << error << "'. " << description;
			MEATBALL_LOG_ERROR(ss.str());
		}
	}
}