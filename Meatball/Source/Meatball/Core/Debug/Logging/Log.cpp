#include <Meatball/Core/Debug/Logging/Log.hpp>

namespace Meatball {
	std::unique_ptr<Logging::ILogger> Log::_logger;

	void Log::Init(std::unique_ptr<Logging::ILogger> logger) {
		_logger = std::move(logger);
	}

	void Log::Debug(const std::string& message, const char* file, int line) {
		_logger->Log(Logging::Severity::Debug, message, file, line);
	}

	void Log::Error(const std::string& message, const char* file, int line) {
		_logger->Log(Logging::Severity::Error, message, file, line);
	}

	void Log::Info(const std::string& message, const char* file, int line) {
		_logger->Log(Logging::Severity::Info, message, file, line);
	}

	void Log::Trace(const std::string& message, const char* file, int line) {
		_logger->Log(Logging::Severity::Trace, message, file, line);
	}

	void Log::Warning(const std::string& message, const char* file, int line) {
		_logger->Log(Logging::Severity::Warning, message, file, line);
	}
}