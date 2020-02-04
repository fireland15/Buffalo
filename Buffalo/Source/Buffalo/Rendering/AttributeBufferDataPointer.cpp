#include <Buffalo/Rendering/AttributeBufferDataPointer.hpp>
#include <Buffalo/Rendering/Buffer.hpp>
#include <Buffalo/Core/Debug.hpp>

namespace Buffalo {
	namespace Rendering {
		AttributeBufferDataPointer::AttributeBufferDataPointer(
			Rendering::Buffer& buffer, 
			GLint elements, 
			AttributeDataType type, 
			GLvoid* offset, 
			GLsizei stride)
			: Buffer(buffer), Elements(elements), Type(type), Offset(offset), Stride(stride) {
			BUFFALO_PROFILE_FUNC();
		}
	}
}