#include <Buffalo/Core/Debug/Logging/Log.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Buffalo {

	Shared<spdlog::logger> Log::_logger;

	void Log::Init() {
		_logger = spdlog::stderr_color_mt("Buffalo");
		
#ifdef BUFFALO_LOG_LEVEL_DEBUG
		_logger->set_level(spdlog::level::debug);
		_logger->info("Logger initialized. Level=debug.");
#elif BUFFALO_LOG_LEVEL_INFO
		_logger->set_level(spdlog::level::info);
		_logger->info("Logger initialized. Level=info.");
#elif BUFFALO_LOG_LEVEL_TRACE
		_logger->set_level(spdlog::level::trace);
		_logger->info("Logger initialized. Level=trace.");
#elif BUFFALO_LOG_LEVEL_WARN
		_logger->set_level(spdlog::level::warn);
		_logger->info("Logger initialized. Level=warn.");
#elif BUFFALO_LOG_LEVEL_ERROR
		_logger->set_level(spdlog::level::err);
		_logger->info("Logger initialized. Level=err.");
#else
		_logger->set_level(spdlog::level::off);
#endif
	}

	void Log::Debug(const std::string& message) {
		_logger->debug(message);
	}

	void Log::Error(const std::string& message, const char* file, int line) {
		_logger->error("{} {} {}", message, file, line);
	}

	void Log::Info(const std::string& message) {
		_logger->info(message);
	}

	void Log::Trace(const std::string& message, const char* file, int line) {
		_logger->trace("{} {} {}", message, file, line);
	}

	void Log::Warning(const std::string& message) {
		_logger->warn(message);
	}
}