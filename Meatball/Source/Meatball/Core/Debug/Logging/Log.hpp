#pragma once 

#include <string>
#include <memory>
#include <Meatball/Core.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>


namespace Meatball {
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

#ifdef MEATBALL_DEBUG
	#define MEATBALL_LOG_DEBUG(x) ::Meatball::Log::Debug(x)
	#define MEATBALL_LOG_ERROR(x) ::Meatball::Log::Error(x, __FILE__, __LINE__)
	#define MEATBALL_LOG_INFO(...) ::Meatball::Log::GetLogger().info(__VA_ARGS__)
	#define MEATBALL_LOG_TRACE(x) ::Meatball::Log::Trace(x, __FILE__, __LINE__)
	#define MEATBALL_LOG_WARNING(x) ::Meatball::Log::Warning(x)
	#define MEATBALL_INIT_LOG() ::Meatball::Log::Init()
#endif //  DEBUG
#ifndef MEATBALL_DEBUG
	#define MEATBALL_LOG_DEBUG(x)
	#define MEATBALL_LOG_ERROR(x)
	#define MEATBALL_LOG_INFO(x)
	#define MEATBALL_LOG_TRACE(x)
	#define MEATBALL_LOG_WARNING(x)
	#define MEATBALL_INIT_LOG(logger)
#endif // !DEBUG
