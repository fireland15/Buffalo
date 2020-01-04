#pragma once 

#include <string>
#include <memory>
#include <Meatball/Core/Debug/Logging/ILogger.hpp>

namespace Meatball {
	class Log {
	public:
		static void Init(std::unique_ptr<Logging::ILogger> logger);
		static void Debug(const std::string& message, const char* file, int line);
		static void Error(const std::string& message, const char* file, int line);
		static void Info(const std::string& message, const char* file, int line);
		static void Trace(const std::string& message, const char* file, int line);
		static void Warning(const std::string& message, const char* file, int line);

	private:
		static std::unique_ptr<Logging::ILogger> _logger;
	};
}

#ifdef MEATBALL_DEBUG
	#define MEATBALL_LOG_DEBUG(x) ::Meatball::Log::Debug(x, __FILE__, __LINE__)
	#define MEATBALL_LOG_ERROR(x) ::Meatball::Log::Error(x, __FILE__, __LINE__)
	#define MEATBALL_LOG_INFO(x) ::Meatball::Log::Info(x, __FILE__, __LINE__)
	#define MEATBALL_LOG_TRACE(x) ::Meatball::Log::Trace(x, __FILE__, __LINE__)
	#define MEATBALL_LOG_WARNING(x) ::Meatball::Log::Warning(x, __FILE__, __LINE__)
	#define MEATBALL_INIT_LOG(logger) ::Meatball::Log::Init(logger)
#endif //  DEBUG
#ifndef MEATBALL_DEBUG
	#define MEATBALL_LOG_DEBUG(x)
	#define MEATBALL_LOG_ERROR(x)
	#define MEATBALL_LOG_INFO(x)
	#define MEATBALL_LOG_TRACE(x)
	#define MEATBALL_LOG_WARNING(x)
	#define MEATBALL_INIT_LOG(logger)
#endif // !DEBUG
