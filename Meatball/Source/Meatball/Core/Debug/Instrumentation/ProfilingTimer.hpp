#pragma once

#include <chrono>

namespace Meatball {
	namespace Instrumentation {
		class ProfilingTimer {
		public:
			ProfilingTimer(const char* name);
			~ProfilingTimer();

			void Stop();
		private:
			void Start();

			const char* name;
			std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
			bool stopped;
		};
	}
}