#pragma once

#include <string>
#include <fstream>
#include <Meatball/Core/Debug/Logging/ILogger.hpp>

namespace Meatball {
	namespace Logging {
		class FileLogger : public ILogger {
		public:
			FileLogger(const char* name);
			virtual ~FileLogger();
			virtual void Log(Severity severity, const std::string& message, const char* file, int line);

		private:
			std::string filename;
			std::ofstream os;
		};
	}
}