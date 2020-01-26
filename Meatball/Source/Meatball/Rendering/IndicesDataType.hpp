#pragma once

#include <glad/glad.h>

namespace Meatball {
	namespace Rendering {
		enum class IndicesDataType : GLenum {
			UnsignedByte = GL_UNSIGNED_BYTE,
			UnsignedShort = GL_UNSIGNED_SHORT,
			UnsignedInt = GL_UNSIGNED_INT
		};
	}
}