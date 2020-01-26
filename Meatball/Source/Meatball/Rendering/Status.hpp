#pragma once

#include <glad/glad.h>

namespace Meatball {
	namespace Rendering {
		enum class Status : GLint {
			Success = GL_TRUE,
			Failure = GL_FALSE
		};
	}
}