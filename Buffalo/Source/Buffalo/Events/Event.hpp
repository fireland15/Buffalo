#pragma once

#include <string>
#include <Buffalo/Events/EventType.hpp>

namespace Buffalo {
	namespace Events {
		class Event {
		public:
			virtual ~Event() = default;

			virtual EventType GetType() = 0;

			virtual const char* GetName() = 0;

			inline bool Handled() { return _handled; }

			void StopPropagation();

		private:
			bool _handled = false;
		};
	}
}