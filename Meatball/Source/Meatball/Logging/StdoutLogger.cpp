#include <Meatball/Logging/StdoutLogger.hpp>
#include <iostream>

namespace Meatball{
	namespace Logging {
		void StdoutLogger::Log(Severity severity, const std::string& message, const char* file, int line) {
			std::cout << "[" << getSeverityString(severity) << "] " << message << "\n\t" << file << "(" << line << ")\n";
		}
	}
}