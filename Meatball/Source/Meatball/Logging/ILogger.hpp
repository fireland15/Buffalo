#pragma once

#include <string>
#include <Meatball/Logging/Severity.hpp>

namespace Meatball {
	namespace Logging {
		class ILogger {
		public:
			virtual ~ILogger() { };
			virtual void Log(Severity severity, const std::string& message, const char* file, int line) = 0;
		};
	}
}