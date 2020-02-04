#pragma once

#include <Buffalo/Rendering/AttributeDataType.hpp>
#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		class Buffer;

		class AttributeBufferDataPointer {
		public:
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