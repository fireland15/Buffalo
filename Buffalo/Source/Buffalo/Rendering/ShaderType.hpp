#pragma once

#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		enum class ShaderType : GLuint {
			Vertex = GL_VERTEX_SHADER,
			Fragment = GL_FRAGMENT_SHADER
		};
	}
}