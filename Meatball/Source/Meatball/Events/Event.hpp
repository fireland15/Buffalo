#pragma once

#include <Meatball/Events/EventType.hpp>

namespace Meatball {
	namespace Events {
		class Event {
		public:
			virtual ~Event() = default;

			virtual EventType GetType() = 0;

			virtual const char* GetName() = 0;

			inline bool Handled() { return handled; }

			void StopPropagation();

		private:
			bool handled = false;
		};
	}
}