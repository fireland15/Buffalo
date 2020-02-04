#include <Buffalo/Rendering/VertexArray.hpp>
#include <Buffalo/Rendering/GL.hpp>
#include <stdexcept>
#include <Buffalo/Rendering/AttributeBufferDataPointer.hpp>
#include <Buffalo/Rendering/Buffer.hpp>
#include <Buffalo/Core/Debug.hpp>

namespace Buffalo {
	namespace Rendering {
		VertexArray::VertexArray()
			: vertexAttributeStates(InitializeVertexAttributeStates()),
			attributeDataPointers(vertexAttributeStates.size(), nullptr) {
			BUFFALO_PROFILE_FUNC();
			GL::GenVertexArrays(1, &handle);
		}

		VertexArray::~VertexArray() {
			BUFFALO_PROFILE_FUNC();
			GL::DeleteVertexArrays(1, &handle);
		}

		void VertexArray::Bind() {
			BUFFALO_PROFILE_FUNC();
			GL::BindVertexArray(handle);
		}

		void VertexArray::DisableAttribute(GLuint index) {
			BUFFALO_PROFILE_FUNC();
			if (!IsBound()) {
				throw std::runtime_error("Cannot disable attribute when the vertex array is not bound.");
			}
			GL::DisableVertexAttribArray(index);
			vertexAttributeStates[index] = false;
		}

		void VertexArray::EnableAttribute(GLuint index) {
			BUFFALO_PROFILE_FUNC();
			if (!IsBound()) {
				throw std::runtime_error("Cannot enable attribute when the vertex array is not bound.");
			}
			GL::EnableVertexAttribArray(index);
			vertexAttributeStates[index] = true;
		}

		GLuint VertexArray::Handle() const {
			BUFFALO_PROFILE_FUNC();
			return handle;
		}

		bool VertexArray::IsBound() const {
			BUFFALO_PROFILE_FUNC();
			GLint currentVertexArray = 0;
			GL::GetIntegerv(ParameterName::VertexArrayBinding, &currentVertexArray);
			return currentVertexArray == static_cast<GLint>(handle);
		}

		void VertexArray::SetAttributePointer(GLuint index, const AttributeBufferDataPointer& dataPointer) {
			BUFFALO_PROFILE_FUNC();
			if (!dataPointer.Buffer.IsBound()) {
				throw std::runtime_error("Cannot set the pointer to the buffer data when the buffer is not currently bound.");
			}
			GL::VertexAttribPointer(index, dataPointer.Elements, dataPointer.Type, false, dataPointer.Stride, dataPointer.Offset);
		}

		void VertexArray::Unbind() {
			BUFFALO_PROFILE_FUNC();
			GL::BindVertexArray(0U);
		}

		bool operator<(const VertexArray& lhs, const VertexArray& rhs) {
			BUFFALO_PROFILE_FUNC();
			return lhs.Handle() < rhs.Handle();
		}

		std::vector<bool> VertexArray::InitializeVertexAttributeStates() {
			BUFFALO_PROFILE_FUNC();
			GLint maxAttributes = 0;
			GL::GetIntegerv(ParameterName::MaxVertexAttributes, &maxAttributes);
			return std::vector<bool>(maxAttributes, false);
		}
	}
}