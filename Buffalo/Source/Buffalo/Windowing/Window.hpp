#pragma once

#include <memory>
#include <functional>
#include <Buffalo/Core.hpp>

namespace Buffalo {
	namespace Events {
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

		private:
			Unique<Events::EventDispatcher> _eventDispatcher;
		};
	}
}