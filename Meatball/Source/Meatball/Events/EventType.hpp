#pragma once

namespace Meatball {
	namespace Events {
		enum class EventType : int {
			Test = 1,
			ApplicationTick = 2,
			ApplicationShutdown = 3
		};
	}
}