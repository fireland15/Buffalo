#pragma once

namespace Buffalo {
	namespace Instrumentation {
		struct ProfileResult {
			const char* Name;
			long long Start;
			long long End;
		};
	}
}