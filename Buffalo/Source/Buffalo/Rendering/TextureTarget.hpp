#pragma once

#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		enum class TextureTarget : GLenum {
			NoTarget = 0U,
			Texture1D = GL_TEXTURE_1D,
			Texture2D = GL_TEXTURE_2D,
			Texture3D = GL_TEXTURE_3D,
			Texture1DArray = GL_TEXTURE_1D_ARRAY,
			Texture2DArray = GL_TEXTURE_2D_ARRAY,
			TextureRectangle = GL_TEXTURE_RECTANGLE,
			TextureCubeMap = GL_TEXTURE_CUBE_MAP,
			TextureCubeMapArray = GL_TEXTURE_CUBE_MAP_ARRAY,
			TextureBuffer = GL_TEXTURE_BUFFER,
			Texture2DMultisample = GL_TEXTURE_2D_MULTISAMPLE,
			Texture2DMultisampleArray = GL_TEXTURE_2D_MULTISAMPLE_ARRAY,
		};
	}
}