#pragma once

#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		enum class BufferUsage : GLenum {
			NoUsage = 0U,
			StaticDraw = GL_STATIC_DRAW
		};
	}
}