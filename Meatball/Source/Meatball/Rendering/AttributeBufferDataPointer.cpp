#include <Meatball/Rendering/AttributeBufferDataPointer.hpp>
#include <Meatball/Rendering/Buffer.hpp>
#include <Meatball/Core/Debug.hpp>

namespace Meatball {
	namespace Rendering {
		AttributeBufferDataPointer::AttributeBufferDataPointer(
			Rendering::Buffer& buffer, 
			GLint elements, 
			AttributeDataType type, 
			GLvoid* offset, 
			GLsizei stride)
			: Buffer(buffer), Elements(elements), Type(type), Offset(offset), Stride(stride) {
			MEATBALL_PROFILE_FUNC();
		}
	}
}