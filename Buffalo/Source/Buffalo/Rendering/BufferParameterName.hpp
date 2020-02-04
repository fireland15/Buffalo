#pragma once

#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		enum class BufferParameterName : GLenum {
			Access = GL_BUFFER_ACCESS,
			AccessFlags = GL_BUFFER_ACCESS_FLAGS,
			Mapped = GL_BUFFER_MAPPED,
			MapLength = GL_BUFFER_MAP_LENGTH,
			MapOffset = GL_BUFFER_MAP_OFFSET,
			Size = GL_BUFFER_SIZE,
			Usage = GL_BUFFER_USAGE
		};
	}
}