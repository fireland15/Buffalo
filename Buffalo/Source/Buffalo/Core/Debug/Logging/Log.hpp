#pragma once 

#include <string>
#include <memory>
#include <Buffalo/Core.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>


namespace Buffalo {
	class Log {
	public:
		
		static void Init();
		
		static void Debug(const std::string& message);
		
		static void Error(const std::string& message, const char* file, int line);
		
		static void Info(const std::string& message);

		static void Trace(const std::string& message, const char* file, int line);

		static void Warning(const std::string& message);

		static spdlog::logger& GetLogger() { return *_logger; }

	private:

		static Shared<spdlog::logger> _logger;

	};
}

#ifdef BUFFALO_DEBUG
	#define BUFFALO_LOG_DEBUG(x) ::Buffalo::Log::Debug(x)
	#define BUFFALO_LOG_ERROR(x) ::Buffalo::Log::Error(x, __FILE__, __LINE__)
	#define BUFFALO_LOG_INFO(...) ::Buffalo::Log::GetLogger().info(__VA_ARGS__)
	#define BUFFALO_LOG_TRACE(x) ::Buffalo::Log::Trace(x, __FILE__, __LINE__)
	#define BUFFALO_LOG_WARNING(x) ::Buffalo::Log::Warning(x)
	#define BUFFALO_INIT_LOG() ::Buffalo::Log::Init()
#endif //  DEBUG
#ifndef BUFFALO_DEBUG
	#define BUFFALO_LOG_DEBUG(x)
	#define BUFFALO_LOG_ERROR(x)
	#define BUFFALO_LOG_INFO(x)
	#define BUFFALO_LOG_TRACE(x)
	#define BUFFALO_LOG_WARNING(x)
	#define BUFFALO_INIT_LOG(logger)
#endif // !DEBUG
