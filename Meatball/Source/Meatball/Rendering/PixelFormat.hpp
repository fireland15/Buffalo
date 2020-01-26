#pragma once

#include <glad/glad.h>

namespace Meatball {
	namespace Rendering {
		enum class PixelFormat : GLenum {
			R = GL_RED,
			RG = GL_RG,
			RGB = GL_RGB,
			BGR = GL_BGR,
			RGBA = GL_RGBA,
			BGRA = GL_BGRA
		};
	}
}