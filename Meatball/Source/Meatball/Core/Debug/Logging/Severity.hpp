#pragma once

#include <string>
#include <Meatball/Core/Bit.hpp>

namespace Meatball {
	namespace Logging {
		enum class Severity : int {
			Trace = BIT(0),
			Error = BIT(1),
			Warning = BIT(2),
			Debug = BIT(3),
			Info = BIT(4)
		};

		const char* getSeverityString(Meatball::Logging::Severity severity);
	}
}