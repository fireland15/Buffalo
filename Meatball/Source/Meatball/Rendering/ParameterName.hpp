#pragma once

#include <glad/glad.h>

namespace Meatball {
	namespace Rendering {
		enum class ParameterName : GLuint {
			ArrayBufferBinding = GL_ARRAY_BUFFER_BINDING,
			CurrentProgram = GL_CURRENT_PROGRAM,
			ElementArrayBufferBinding = GL_ELEMENT_ARRAY_BUFFER_BINDING,
			MaxVertexAttributes = GL_MAX_VERTEX_ATTRIBS,
			VertexArrayBinding = GL_VERTEX_ARRAY_BINDING
		};
	}
}