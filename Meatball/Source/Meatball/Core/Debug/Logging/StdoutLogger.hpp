#pragma once

#include <Meatball/Core/Debug/Logging/ILogger.hpp>

namespace Meatball {
	namespace Logging {
		class StdoutLogger : public ILogger {
		public:
			virtual ~StdoutLogger() = default;
			virtual void Log(Severity severity, const std::string& message, const char* file, int line);
		};
	}
}