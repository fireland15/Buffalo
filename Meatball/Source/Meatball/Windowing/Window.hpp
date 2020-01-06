#pragma once

#include <memory>
#include <functional>
#include <Meatball/Core.hpp>
#include <Meatball/Events/EventDispatcher.hpp>
#include <Meatball/Windowing/WindowProps.hpp>

namespace Meatball {
	namespace Events {
		class EventDispatcher;
	}

	namespace Windowing {
		class Window {
		public:
			Window(Unique<Events::EventDispatcher> eventDispatcher) : _eventDispatcher(std::move(eventDispatcher)) {}

			virtual ~Window() = default;

			virtual void OnUpdate() = 0;

		protected:
			inline Events::EventDispatcher& GetEventDispatcher() { return *_eventDispatcher; }

			inline Events::EventBus& GetEventBus() { return _eventDispatcher->GetEventBus(); }

		private:
			Unique<Events::EventDispatcher> _eventDispatcher;
		};
	}
}