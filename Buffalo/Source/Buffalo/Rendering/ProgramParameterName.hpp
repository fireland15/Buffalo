#pragma once

#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		enum class ProgramParameterName : GLenum {
			DeleteStatus = GL_DELETE_STATUS,
			LinkStatus = GL_LINK_STATUS,
			ValidateStatus = GL_VALIDATE_STATUS,
			InfoLogLength = GL_INFO_LOG_LENGTH,
			AttachedShaders = GL_ATTACHED_SHADERS,
			ActiveAttributes = GL_ACTIVE_ATTRIBUTES,
			ActiveAttributeMaxLength = GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,
			ActiveUniforms = GL_ACTIVE_UNIFORMS,
			ActiveUniformMaxLength = GL_ACTIVE_UNIFORM_MAX_LENGTH,
			ProgramBinaryLength = GL_PROGRAM_BINARY_LENGTH,
			TransformFeedbackBufferMode = GL_TRANSFORM_FEEDBACK_BUFFER_MODE,
			TransformFeedbackVaryingMaxLength = GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH,
			GeometryVerticesOut = GL_GEOMETRY_VERTICES_OUT,
			GeometryInputType = GL_GEOMETRY_INPUT_TYPE,
			GeometryOutputType = GL_GEOMETRY_OUTPUT_TYPE
		};
	}
}