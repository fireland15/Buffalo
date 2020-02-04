#pragma once

#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		enum class Status : GLint {
			Success = GL_TRUE,
			Failure = GL_FALSE
		};
	}
}