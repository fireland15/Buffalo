#include <Platform/Glfw/GlfwWindow.hpp>
#include <sstream>
#include <GLFW/glfw3.h>
#include <Buffalo/Core/Debug.hpp>
#include <Buffalo/Core/InputState.hpp>
#include <Buffalo/Core/Keys.hpp>
#include <Buffalo/Events/EventBus.hpp>
#include <Buffalo/Events/WindowEvent.hpp>
#include <Buffalo/Events/KeyEvent.hpp>
#include <Buffalo/Events/MouseEvent.hpp>
#include <Buffalo/Events/EventDispatcher.hpp>
#include <Buffalo/Rendering/GraphicsContext.hpp>
#include <Buffalo/Events/EventBus.hpp>
#include <Platform/Glfw/GlfwInputAdapter.hpp>

namespace Buffalo {
	namespace Windowing {
		int GlfwWindow::_glfwWindowCount = 0;

		void glfwErrorCallback(int error, const char* description);

		//////////////////////////////////////
		// Constructor(s) / Destructor
		//////////////////////////////////////

		GlfwWindow::GlfwWindow(Unique<Events::EventDispatcher> eventDispatcher, const WindowProps & windowProps)
			: Window(std::move(eventDispatcher)) {
			BUFFALO_PROFILE_FUNC();
			if (_glfwWindowCount == 0) {
				glfwSetErrorCallback(glfwErrorCallback);
				BUFFALO_LOG_INFO("Initializing GLFW.");
				int glfwInitResult = glfwInit();
				if (!glfwInitResult) {
					BUFFALO_LOG_ERROR("Failed to initialize GLFW!");
					throw std::runtime_error("Failed to initialize GLFW!");
				}
			}

			GetEventDispatcher()
				.AddEventHandler(Events::EventType::ApplicationShutdown, BUFFALO_BIND_EVENT_HANDLER(GlfwWindow::OnApplicationShutdown));

			BUFFALO_LOG_INFO("Creating GLFW Window.");
			_glfwWindow = glfwCreateWindow(windowProps.Width, windowProps.Height, windowProps.Title, nullptr, nullptr);
			if (_glfwWindow == nullptr) {
				BUFFALO_LOG_ERROR("Failed to create a GLFW window!");
				throw std::runtime_error("Failed to create a GLFW window!");
			}

			_context = std::make_unique<Rendering::GraphicsContext>(_glfwWindow);
			_context->Init();

			_inputAdapter = std::make_unique<Core::GlfwInputAdapter>(_glfwWindow);
			InputState::SetAdapter(_inputAdapter.get());

			glfwSetWindowUserPointer(_glfwWindow, static_cast<void*>(this));
			glfwSetWindowCloseCallback(_glfwWindow, &GlfwWindow::glfwWindowCloseCallback);
			glfwSetKeyCallback(_glfwWindow, &GlfwWindow::glfwKeyCallback);
			glfwSetCursorPosCallback(_glfwWindow, &GlfwWindow::glfwCursorPosCallback);
			glfwSetMouseButtonCallback(_glfwWindow, &GlfwWindow::glfwMouseButtonCallback);

			glfwSwapInterval(0);
		}

		GlfwWindow::~GlfwWindow() {
			BUFFALO_PROFILE_FUNC();
			if (_glfwWindowCount-- == 0) {
				BUFFALO_LOG_INFO("Terminating GLFW.");
				glfwTerminate();
			}

			InputState::ReleaseAdapter();
		}

		//////////////////////////////////////
		// Lifetime Methods
		//////////////////////////////////////

		void GlfwWindow::OnUpdate() {
			BUFFALO_PROFILE_FUNC();
			_context->SwapBuffers();
			glfwPollEvents();
		}

		void GlfwWindow::Terminate() {
			BUFFALO_PROFILE_FUNC();
			BUFFALO_LOG_INFO("Closing Window.");
			glfwDestroyWindow(_glfwWindow);
			_glfwWindow = nullptr;
		}

		//////////////////////////////////////
		// Event Handlers
		//////////////////////////////////////

		void GlfwWindow::OnApplicationShutdown(Shared<Events::Event> event) {
			BUFFALO_PROFILE_FUNC();
			BUFFALO_LOG_INFO("Closing Window.");
			glfwDestroyWindow(_glfwWindow);
		}

		//////////////////////////////////////
		// GLFW Callback Handlers
		//////////////////////////////////////

		void GlfwWindow::HandleWindowClosed() {
			BUFFALO_PROFILE_FUNC();
			EventBus::Publish<Events::WindowClosedEvent>();
		}

		void GlfwWindow::HandleKeyEvent(int key, int scancode, int action, int mods) {
			BUFFALO_PROFILE_FUNC();
			switch (action) {
			case GLFW_RELEASE:
				EventBus::Publish<Events::KeyReleasedEvent>(static_cast<Key>(key));
				return;
			case GLFW_PRESS:
				EventBus::Publish<Events::KeyPressedEvent>(static_cast<Key>(key));
				return;
			case GLFW_REPEAT:
			default:
				return;
			}
		}

		void GlfwWindow::HandleCursorPosEvent(double xpos, double ypos) {
			BUFFALO_PROFILE_FUNC();
			EventBus::Publish<Events::MouseMovedEvent>(xpos, ypos);
		}

		void GlfwWindow::HandleMouseButtonEvent(int button, int action, int mods) {
			BUFFALO_PROFILE_FUNC();
			switch (action) {
			case GLFW_PRESS:
				EventBus::Publish<Events::MouseButtonPressedEvent>(static_cast<MouseCodes>(button));
				return;
			case GLFW_RELEASE:
				EventBus::Publish<Events::MouseButtonReleasedEvent>(static_cast<MouseCodes>(button));
				return;
			default:
				return;
			}
		}

		//////////////////////////////////////
		// Static Methods
		//////////////////////////////////////

		void GlfwWindow::glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			BUFFALO_PROFILE_FUNC();
			GlfwWindow* buffaloWindow = static_cast<GlfwWindow*>(glfwGetWindowUserPointer(window));
			buffaloWindow->HandleKeyEvent(key, scancode, action, mods);
		}

		void GlfwWindow::glfwWindowCloseCallback(GLFWwindow* window) {
			BUFFALO_PROFILE_FUNC();
			GlfwWindow* buffaloWindow = static_cast<GlfwWindow*>(glfwGetWindowUserPointer(window));
			buffaloWindow->HandleWindowClosed();
		}

		void GlfwWindow::glfwCursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
			BUFFALO_PROFILE_FUNC();
			GlfwWindow* buffaloWindow = static_cast<GlfwWindow*>(glfwGetWindowUserPointer(window));
			buffaloWindow->HandleCursorPosEvent(xpos, ypos);
		}

		void GlfwWindow::glfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
			BUFFALO_PROFILE_FUNC();
			GlfwWindow* buffaloWindow = static_cast<GlfwWindow*>(glfwGetWindowUserPointer(window));
			buffaloWindow->HandleMouseButtonEvent(button, action, mods);
		}

		void glfwErrorCallback(int error, const char* description) {
			std::stringstream ss;
			ss << "GLFW error '" << error << "'. " << description;
			BUFFALO_LOG_ERROR(ss.str());
		}
	}
}