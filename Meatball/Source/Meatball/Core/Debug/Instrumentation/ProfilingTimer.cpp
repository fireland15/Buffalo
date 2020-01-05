#include <Meatball/Core/Debug/Instrumentation/ProfilingTimer.hpp>
#include <chrono>
#include <Meatball/Core/Debug/Instrumentation/Profiler.hpp>

namespace Meatball {
	namespace Instrumentation {
		ProfilingTimer::ProfilingTimer(const char* name)
			: name(name), stopped(false) {
			Start();
		}

		ProfilingTimer::~ProfilingTimer() {
			if (!stopped)
				Stop();
		}

		void ProfilingTimer::Start() {
			startTime = std::chrono::high_resolution_clock::now();
		}

		void ProfilingTimer::Stop() {
			auto endTime = std::chrono::high_resolution_clock::now();
			auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTime).time_since_epoch().count();
			auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();

			GetProfiler().WriteResult({ name, start, end });
		}
	}
}