#pragma once

#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		enum class TextureParameterName : GLenum {
			TextureMagFilter = GL_TEXTURE_MAG_FILTER,
			TextureMinFilter = GL_TEXTURE_MIN_FILTER
		};
	}
}