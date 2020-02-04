#pragma once 

#include <string>
#include <Buffalo/Rendering/UniformDataType.hpp>

namespace Buffalo {
	namespace Rendering {
		struct UniformVariable {
			const UniformDataType Type;
			const GLint Location;
			const std::string Name;
			const GLint Size;

			UniformVariable();

			UniformVariable(
				GLint location, 
				UniformDataType type, 
				GLint size, 
				std::string& name);
		};
	}
}