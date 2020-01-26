#pragma once

#include <Meatball/Rendering/AttributeDataType.hpp>

namespace Meatball {
	namespace Rendering {
		class Buffer;

		struct AttributeBufferDataPointer {
			const GLint Elements = 0;
			const AttributeDataType Type;
			const GLvoid* Offset = 0;
			const GLsizei Stride = 0;
			const Rendering::Buffer& Buffer;

			AttributeBufferDataPointer(
				Rendering::Buffer& buffer,
				GLint elements, 
				AttributeDataType type, 
				GLvoid* offset,
				GLsizei stride);
		};
	}
}