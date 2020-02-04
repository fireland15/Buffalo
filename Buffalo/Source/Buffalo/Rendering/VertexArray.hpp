#pragma once

#include <vector>
#include <glad/glad.h>

namespace Buffalo {
	namespace Rendering {
		class AttributeBufferDataPointer;

		class VertexArray {
		public:
			VertexArray();
			VertexArray(const VertexArray& other) = delete;
			VertexArray(VertexArray&& other) = delete;
			VertexArray& operator=(const VertexArray& other) = delete;
			VertexArray& operator=(VertexArray&& other) = delete;
			~VertexArray();

			void Bind();
			void DisableAttribute(GLuint index);
			void EnableAttribute(GLuint index);
			GLuint Handle() const;
			bool IsBound() const;
			void SetAttributePointer(GLuint index, const AttributeBufferDataPointer& dataPointe);
			void Unbind();

			friend bool operator<(const VertexArray& lhs, const VertexArray& rhs);

		private:
			std::vector<bool> InitializeVertexAttributeStates();

		private:
			GLuint handle = 0U;
			std::vector<bool> vertexAttributeStates;
			std::vector<AttributeBufferDataPointer*> attributeDataPointers;
		};
	}
}