#pragma once

#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		enum class TextureInternalFormat : GLenum {
			RGB = GL_RGB,
			RGBA = GL_RGBA
		};
	}
}