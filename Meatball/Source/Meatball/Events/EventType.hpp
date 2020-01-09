#pragma once

namespace Meatball {
	namespace Events {
		enum class EventType : int {
			ApplicationTick,
			ApplicationShutdown,
			WindowClosed,
			KeyPressed,
			KeyReleased,
			MouseMoved,
			MouseButtonPressed,
			MouseButtonReleased
		};
	}
}