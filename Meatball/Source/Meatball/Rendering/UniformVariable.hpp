#pragma once 

#include <string>
#include <Meatball/Rendering/UniformDataType.hpp>

namespace Meatball {
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