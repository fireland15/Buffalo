#pragma once

#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		enum class Capability : GLenum {
			DepthTest = GL_DEPTH_TEST,
			ScissorTest = GL_SCISSOR_TEST
		};
	}
}