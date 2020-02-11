#include <Platform/Glfw/GlfwInputAdapter.hpp>
#include <Buffalo/Core/Debug.hpp>
#include <Buffalo/Events/EventDispatcher.hpp>
#include <Buffalo/Events/MouseEvent.hpp>
#include <Buffalo/Events/KeyEvent.hpp>
#include <memory>
#include <GLFW/glfw3.h>

namespace Buffalo {
	namespace Core {

		GlfwInputAdapter::GlfwInputAdapter(GLFWwindow* window)
			: _window(window)
			, _eventDispatcher(std::move(EventBus::GetDispatcher()))
			, _mousePosition()
			, _mousePositionDifferential() {
			BUFFALO_PROFILE_FUNC();

			BUFFALO_ADD_EVENT_HANDLER(_eventDispatcher, Events::EventType::MouseButtonPressed, GlfwInputAdapter::OnMouseButtonPressed);
			BUFFALO_ADD_EVENT_HANDLER(_eventDispatcher, Events::EventType::MouseButtonReleased, GlfwInputAdapter::OnMouseButtonReleased);
			BUFFALO_ADD_EVENT_HANDLER(_eventDispatcher, Events::EventType::KeyPressed, GlfwInputAdapter::OnKeyPressed);
			BUFFALO_ADD_EVENT_HANDLER(_eventDispatcher, Events::EventType::KeyReleased, GlfwInputAdapter::OnKeyReleased);
			BUFFALO_ADD_EVENT_HANDLER(_eventDispatcher, Events::EventType::MouseMoved, GlfwInputAdapter::OnMouseMoved);
		}

		GlfwInputAdapter::~GlfwInputAdapter() = default;

		bool GlfwInputAdapter::IsKeyPressed(Key key) {
			BUFFALO_PROFILE_FUNC();
			const auto it = _keyStates.find(key);
			if (it == _keyStates.end()) {
				return false;
			}
			return it->second;
		}

		bool GlfwInputAdapter::IsMouseButtonPressed(MouseCodes mouseCode) {
			BUFFALO_PROFILE_FUNC();
			const auto it = _mouseButtonStates.find(mouseCode);
			if (it == _mouseButtonStates.end()) {
				return false;
			}
			return it->second;
		}

		glm::vec2 GlfwInputAdapter::GetMousePosition() {
			BUFFALO_PROFILE_FUNC();
			return _mousePosition;
		}

		glm::vec2 GlfwInputAdapter::GetMousePositionDifferential() {
			BUFFALO_PROFILE_FUNC();
			return _mousePositionDifferential;
		}

		void GlfwInputAdapter::OnUpdate() {
			_mousePositionDifferential = glm::vec2(0.f);
			_eventDispatcher->DispatchEvents();
		}

		void GlfwInputAdapter::OnMouseButtonPressed(Buffalo::Shared<Events::Event> event) {
			auto mouseButtonPressedEvent = static_cast<Events::MouseButtonPressedEvent*>(event.get());
			auto mouseCode = mouseButtonPressedEvent->GetMouseCode();
			if (_mouseButtonStates.count(mouseCode) == 0) {
				_mouseButtonStates.emplace(mouseCode, true);
			}
			else {
				_mouseButtonStates[mouseCode] = true;
			}
		}

		void GlfwInputAdapter::OnMouseButtonReleased(Buffalo::Shared<Events::Event> event) {
			auto mouseButtonReleaseEvent = static_cast<Events::MouseButtonReleasedEvent*>(event.get());
			auto mouseCode = mouseButtonReleaseEvent->GetMouseCode();
			if (_mouseButtonStates.count(mouseCode) == 0) {
				_mouseButtonStates.emplace(mouseCode, false);
			}
			else {
				_mouseButtonStates[mouseCode] = false;
			}
		}

		void GlfwInputAdapter::OnKeyPressed(Buffalo::Shared<Events::Event> event) {
			auto keyPressedEvent = static_cast<Events::KeyPressedEvent*>(event.get());
			auto key = keyPressedEvent->GetKey();
			if (_keyStates.count(key) == 0) {
				_keyStates.emplace(key, true);
			}
			else {
				_keyStates[key] = true;
			}
		}

		void GlfwInputAdapter::OnKeyReleased(Buffalo::Shared<Events::Event> event) {
			auto keyReleasedEvent = static_cast<Events::KeyReleasedEvent*>(event.get());
			auto key = keyReleasedEvent->GetKey();
			if (_keyStates.count(key) == 0) {
				_keyStates.emplace(key, false);
			}
			else {
				_keyStates[key] = false;
			}
		}

		void GlfwInputAdapter::OnMouseMoved(Buffalo::Shared<Events::Event> event) {
			auto mouseMovedEvent = static_cast<Events::MouseMovedEvent*>(event.get());
			auto position = mouseMovedEvent->GetPosition();
			_mousePositionDifferential = position - _mousePosition;
			_mousePosition = position;
		}

	}
}