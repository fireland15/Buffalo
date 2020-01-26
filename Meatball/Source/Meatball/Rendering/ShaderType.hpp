#pragma once

#include <glad/glad.h>

namespace Meatball {
	namespace Rendering {
		enum class ShaderType : GLuint {
			Vertex = GL_VERTEX_SHADER,
			Fragment = GL_FRAGMENT_SHADER
		};
	}
}