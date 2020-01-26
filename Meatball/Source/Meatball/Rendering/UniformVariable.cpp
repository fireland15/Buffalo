#include <Meatball/Rendering/UniformVariable.hpp>
#include <Meatball/Core/Debug.hpp>

namespace Meatball {
	namespace Rendering {
		UniformVariable::UniformVariable()
			: Location(0), Type(UniformDataType::Float), Name(""), Size(0) {
			MEATBALL_PROFILE_FUNC();
		}

		UniformVariable::UniformVariable(
			GLint location, 
			UniformDataType type, 
			GLint size, 
			std::string& name)
			: Location(location), Type(type), Name(name), Size(size) { 
			MEATBALL_PROFILE_FUNC();
		}
	}
}