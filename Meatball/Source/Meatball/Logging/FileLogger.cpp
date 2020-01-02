#include <Meatball/Logging/FileLogger.hpp>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>

std::string getShortDate() {
	auto now = std::chrono::system_clock::now();
	auto time = std::chrono::system_clock::to_time_t(now);
	std::stringstream ss;
	ss << std::put_time(std::localtime(&time), "%Y.%m.%d.%H.%M.%S");
	return ss.str();
}

namespace Meatball {
	namespace Logging {
		FileLogger::FileLogger(const char* name) {
			std::stringstream ss_filename;
			ss_filename << getShortDate() << "." << name << ".mbl";
			filename = ss_filename.str();
			os.open(filename);
			if (!os.is_open()) {
				throw std::exception("Failed to open the log file.");
			}
		}

		FileLogger::~FileLogger() {
			os.close();
		}

		void FileLogger::Log(Severity severity, const std::string& message, const char* file, int line) {
			os << "[" << getSeverityString(severity) << "] " << message << "\n\t" << file << "(" << line << ")\n";
		}
	}
}