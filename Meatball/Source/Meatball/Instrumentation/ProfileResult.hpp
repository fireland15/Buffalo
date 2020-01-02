#pragma once

namespace Meatball {
	namespace Instrumentation {
		struct ProfileResult {
			const char* Name;
			long long Start;
			long long End;
		};
	}
}