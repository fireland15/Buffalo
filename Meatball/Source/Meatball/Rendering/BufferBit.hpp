#pragma once

#include <glad/glad.h>

namespace Meatball {
	namespace Rendering {
		enum class BufferBit : GLbitfield {
			Color = GL_COLOR_BUFFER_BIT,
			Depth = GL_DEPTH_BUFFER_BIT,
			Stencil = GL_STENCIL_BUFFER_BIT
		};
	}
}