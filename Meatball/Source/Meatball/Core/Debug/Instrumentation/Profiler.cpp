#include <Meatball/Core/Debug/Instrumentation/Profiler.hpp>
#include <exception>
#include <algorithm>

static Meatball::Instrumentation::Profiler PROFILER;

namespace Meatball {
	namespace Instrumentation {
		Profiler::Profiler() 
			: profileCount(0) {
			fileStream.open("profile.json");
			if (!fileStream.is_open()) {
				throw std::runtime_error("Failed to open profile.json");
			}
			fileStream << "[";
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

		Profiler& GetProfiler() {
			return PROFILER;
		}
	}
}