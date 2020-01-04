#include <Meatball/Core/Debug/Logging/Severity.hpp>
#include <string>

namespace Meatball {
	namespace Logging {
		const char* getSeverityString(Meatball::Logging::Severity severity) {
			switch (severity) {
			case Meatball::Logging::Severity::Debug: return "Debug";
			case Meatball::Logging::Severity::Error: return "Error";
			case Meatball::Logging::Severity::Info: return "Info";
			case Meatball::Logging::Severity::Trace: return "Trace";
			case Meatball::Logging::Severity::Warning: return "Warning";
			default: return "Unknown";
			}
		}
	}
}