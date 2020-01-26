#pragma once

#include <glad/glad.h>

namespace Meatball {
	namespace Rendering {
		enum class BufferTarget : GLenum {
			NoTarget = 0U,
			ArrayBuffer = GL_ARRAY_BUFFER,
			ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER
		};
	}
}