#include <Buffalo/Core/Debug/Instrumentation/Profiler.hpp>
#include <exception>
#include <algorithm>
#include <Buffalo/Core/Debug.hpp>

static Buffalo::Instrumentation::Profiler PROFILER;

namespace Buffalo {
	namespace Instrumentation {
		Profiler::Profiler() 
			: profileCount(0) {
		}

		Profiler::~Profiler() {
			fileStream << "]";
		}

		void Profiler::WriteResult(const ProfileResult& result) {
			if (profileCount++ > 0)
				fileStream << ",";

			std::string name(result.Name);
			std::replace(name.begin(), name.end(), '"', '\'');

			fileStream << "{";
			fileStream << "\"cat\":\"function\",";
			fileStream << "\"dur\":" << (result.End - result.Start) << ',';
			fileStream << "\"name\":\"" << name << "\",";
			fileStream << "\"ph\":\"X\",";
			fileStream << "\"pid\":0,";
			fileStream << "\"tid\":0,";
			fileStream << "\"ts\":" << result.Start;
			fileStream << "}";

			fileStream.flush();
		}

		void Profiler::Init() {
			fileStream.open("profile.json");
			if (!fileStream.is_open()) {
				BUFFALO_LOG_ERROR("Failed to open 'profile.json' for profiler.");
				throw std::runtime_error("Failed to open profile.json");
			}
			BUFFALO_LOG_INFO("Profiler Initialized. Writing to 'profile.json'.");
			fileStream << "[";
		}

		Profiler& GetProfiler() {
			return PROFILER;
		}
	}
}