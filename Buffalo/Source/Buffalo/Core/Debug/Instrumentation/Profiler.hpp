#pragma once

#include <fstream>
#include <Buffalo/Core/Debug/Instrumentation/ProfileResult.hpp>
#include <Buffalo/Core/Debug/Instrumentation/ProfilingTimer.hpp>

namespace Buffalo {
	namespace Instrumentation {
		class Profiler {
		public:
			
			Profiler();
			
			~Profiler();
			
			void WriteResult(const ProfileResult& result);

			void Init();

		private:
			std::ofstream fileStream;
			int profileCount;
		};

		Profiler& GetProfiler();
	}
}

#ifdef BUFFALO_PROFILE
	#define BUFFALO_PROFILE_INIT() ::Buffalo::Instrumentation::GetProfiler().Init();
	#define BUFFALO_PROFILE_SCOPE(name) ::Buffalo::Instrumentation::ProfilingTimer timer##__LINE__(name)
	#define BUFFALO_PROFILE_FUNC() BUFFALO_PROFILE_SCOPE(__func__)
#endif
#ifndef BUFFALO_PROFILE
	#define BUFFALO_PROFILE_INIT()
	#define BUFFALO_PROFILE_SCOPE(name)
	#define BUFFALO_PROFILE_FUNC()
#endif // !BUFFALO_PROFILE
