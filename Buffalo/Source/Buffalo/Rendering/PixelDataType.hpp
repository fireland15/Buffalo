#pragma once

#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		enum class PixelDataType : GLenum {
			Byte = GL_BYTE,
			Float = GL_FLOAT
		};
	}
}