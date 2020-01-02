#pragma once

#include <fstream>
#include <Meatball/Instrumentation/ProfileResult.hpp>
#include <Meatball/Instrumentation/ProfilingTimer.hpp>

namespace Meatball {
	namespace Instrumentation {
		class Profiler {
		public:
			Profiler();
			~Profiler();
			void WriteResult(const ProfileResult& result);

		private:
			std::ofstream fileStream;
			int profileCount;
		};

		Profiler& GetProfiler();
	}
}

#ifdef MEATBALL_PROFILE
	#define MEATBALL_PROFILE_SCOPE(name) ::Meatball::Instrumentation::ProfilingTimer timer##__LINE__(name)
	#define MEATBALL_PROFILE_FUNC() MEATBALL_PROFILE_SCOPE(__func__)
#endif
#ifndef MEATBALL_PROFILE
	#define MEATBALL_PROFILE_SCOPE(name)
	#define MEATBALL_PROFILE_FUNC
#endif // !MEATBALL_PROFILE
