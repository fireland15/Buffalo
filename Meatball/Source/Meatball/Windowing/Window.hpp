#pragma once

#include <memory>
#include <functional>
#include <Meatball/Core.hpp>

namespace Meatball {
	namespace Events {
		class EventBus;
		class EventDispatcher;
	}

	namespace Windowing {
		class Window {
		public:
			Window(Unique<Events::EventDispatcher> eventDispatcher);

			virtual ~Window() = default;

			virtual void OnUpdate() = 0;

			virtual void Terminate() = 0;

		protected:
			Events::EventDispatcher& GetEventDispatcher();

			Events::EventBus& GetEventBus();

		private:
			Unique<Events::EventDispatcher> _eventDispatcher;
		};
	}
}