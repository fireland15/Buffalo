#pragma once

#include <memory>
#include <functional>
#include <Meatball/Core.hpp>
#include <Meatball/Windowing/WindowProps.hpp>

namespace Meatball {
	namespace Events {
		class EventBus;
	}

	namespace Windowing {
		class Window {
		public:
			virtual ~Window() = default;

			virtual void AttachEventBus(Events::EventBus& eventBus) = 0;
		};
	}
}