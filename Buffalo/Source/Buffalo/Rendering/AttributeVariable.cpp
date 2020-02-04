#include <Buffalo/Rendering/AttributeVariable.hpp>
#include <Buffalo/Core/Debug.hpp>

namespace Buffalo {
	namespace Rendering {
		AttributeVariable::AttributeVariable(AttributeDataType type, GLint location, const std::string& name, GLint size) 
			: Type(type)
			, Location(location)
			, Name(name)
			, Size(size) {
			BUFFALO_PROFILE_FUNC();
		}
	}
}