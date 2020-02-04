#pragma once

#include <Buffalo/Events/Event.hpp>
#include <Buffalo/Core/Keys.hpp>

namespace Buffalo {
	namespace Events {
		class KeyEvent : public Event {
		public:

			KeyEvent(Key key) : _key(key) { }

			virtual ~KeyEvent() = default;

		private:

			Key _key;

		};

		class KeyPressedEvent : public KeyEvent {
		public:

			KeyPressedEvent(Key key) : KeyEvent(key) { }

			virtual ~KeyPressedEvent() = default;

			virtual EventType GetType() { return EventType::KeyPressed; }

			virtual const char* GetName() { return "KeyPressedEvent"; }

		};

		class KeyReleasedEvent : public KeyEvent {
		public:

			KeyReleasedEvent(Key key) : KeyEvent(key) { }

			virtual ~KeyReleasedEvent() = default;

			virtual EventType GetType() { return EventType::KeyReleased; }

			virtual const char* GetName() { return "KeyReleasedEvent"; }

		};
	}
}