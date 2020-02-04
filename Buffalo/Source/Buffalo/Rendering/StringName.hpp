#pragma once

#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		enum class StringName : GLuint {
			Vendor = GL_VENDOR,
			Renderer = GL_RENDERER,
			Version = GL_VERSION,
			ShadingLanguageVersion = GL_SHADING_LANGUAGE_VERSION
		};
	}
}