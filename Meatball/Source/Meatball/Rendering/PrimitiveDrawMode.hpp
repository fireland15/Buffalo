#pragma once

#include <glad/glad.h>

namespace Meatball {
	namespace Rendering {
		enum class PrimitiveDrawMode : unsigned int {
			Points = GL_POINTS,
			Lines = GL_LINES,
			Triangles = GL_TRIANGLES
		};
	}
}