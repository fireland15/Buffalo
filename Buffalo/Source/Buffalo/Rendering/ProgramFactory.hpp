#pragma once

#include <Buffalo/Core/TypeDefs.hpp>
#include <string>

namespace Buffalo {
	namespace Rendering {
		class Program;

		class ProgramFactory {
		public:
			Unique<Program> CreateProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);

		private:

		};
	}
}