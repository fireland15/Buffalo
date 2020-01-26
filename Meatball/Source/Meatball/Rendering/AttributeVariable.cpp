#include <Meatball/Rendering/AttributeVariable.hpp>
#include <Meatball/Core/Debug.hpp>

namespace Meatball {
	namespace Rendering {
		AttributeVariable::AttributeVariable(AttributeDataType type, GLint location, const std::string& name, GLint size) 
			: Type(type)
			, Location(location)
			, Name(name)
			, Size(size) {
			MEATBALL_PROFILE_FUNC();
		}
	}
}