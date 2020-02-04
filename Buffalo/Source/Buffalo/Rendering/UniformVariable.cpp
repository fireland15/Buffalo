#include <Buffalo/Rendering/UniformVariable.hpp>
#include <Buffalo/Core/Debug.hpp>

namespace Buffalo {
	namespace Rendering {
		UniformVariable::UniformVariable()
			: Location(0), Type(UniformDataType::Float), Name(""), Size(0) {
			BUFFALO_PROFILE_FUNC();
		}

		UniformVariable::UniformVariable(
			GLint location, 
			UniformDataType type, 
			GLint size, 
			std::string& name)
			: Location(location), Type(type), Name(name), Size(size) { 
			BUFFALO_PROFILE_FUNC();
		}
	}
}