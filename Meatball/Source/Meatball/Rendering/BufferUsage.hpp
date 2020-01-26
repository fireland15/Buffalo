#pragma once

#include <glad/glad.h>

namespace Meatball {
	namespace Rendering {
		enum class BufferUsage : GLenum {
			NoUsage = 0U,
			StaticDraw = GL_STATIC_DRAW
		};
	}
}