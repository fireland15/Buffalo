#pragma once

#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		enum class AttributeDataType : GLenum {
			Float = GL_FLOAT,
			FloatVec2 = GL_FLOAT_VEC2,
			FloatVec3 = GL_FLOAT_VEC3,
			FloatVec4 = GL_FLOAT_VEC4,
			FloatMat2 = GL_FLOAT_MAT2,
			FloatMat3 = GL_FLOAT_MAT3,
			FloatMat4 = GL_FLOAT_MAT4,
		};
	}
}