#include <Meatball/Rendering/VertexArray.hpp>
#include <Meatball/Rendering/GL.hpp>
#include <stdexcept>
#include <Meatball/Rendering/AttributeBufferDataPointer.hpp>
#include <Meatball/Rendering/Buffer.hpp>
#include <Meatball/Core/Debug.hpp>

namespace Meatball {
	namespace Rendering {
		VertexArray::VertexArray()
			: vertexAttributeStates(InitializeVertexAttributeStates()),
			attributeDataPointers(vertexAttributeStates.size(), nullptr) {
			MEATBALL_PROFILE_FUNC();
			GL::GenVertexArrays(1, &handle);
		}

		VertexArray::~VertexArray() {
			MEATBALL_PROFILE_FUNC();
			GL::DeleteVertexArrays(1, &handle);
		}

		void VertexArray::Bind() {
			MEATBALL_PROFILE_FUNC();
			GL::BindVertexArray(handle);
		}

		void VertexArray::DisableAttribute(GLuint index) {
			MEATBALL_PROFILE_FUNC();
			if (!IsBound()) {
				throw std::runtime_error("Cannot disable attribute when the vertex array is not bound.");
			}
			GL::DisableVertexAttribArray(index);
			vertexAttributeStates[index] = false;
		}

		void VertexArray::EnableAttribute(GLuint index) {
			MEATBALL_PROFILE_FUNC();
			if (!IsBound()) {
				throw std::runtime_error("Cannot enable attribute when the vertex array is not bound.");
			}
			GL::EnableVertexAttribArray(index);
			vertexAttributeStates[index] = true;
		}

		GLuint VertexArray::Handle() const {
			MEATBALL_PROFILE_FUNC();
			return handle;
		}

		bool VertexArray::IsBound() const {
			MEATBALL_PROFILE_FUNC();
			GLint currentVertexArray = 0;
			GL::GetIntegerv(ParameterName::VertexArrayBinding, &currentVertexArray);
			return currentVertexArray == static_cast<GLint>(handle);
		}

		void VertexArray::SetAttributePointer(GLuint index, const AttributeBufferDataPointer& dataPointer) {
			MEATBALL_PROFILE_FUNC();
			if (!dataPointer.Buffer.IsBound()) {
				throw std::runtime_error("Cannot set the pointer to the buffer data when the buffer is not currently bound.");
			}
			GL::VertexAttribPointer(index, dataPointer.Elements, dataPointer.Type, false, dataPointer.Stride, dataPointer.Offset);
		}

		void VertexArray::Unbind() {
			MEATBALL_PROFILE_FUNC();
			GL::BindVertexArray(0U);
		}

		bool operator<(const VertexArray& lhs, const VertexArray& rhs) {
			MEATBALL_PROFILE_FUNC();
			return lhs.Handle() < rhs.Handle();
		}

		std::vector<bool> VertexArray::InitializeVertexAttributeStates() {
			MEATBALL_PROFILE_FUNC();
			GLint maxAttributes = 0;
			GL::GetIntegerv(ParameterName::MaxVertexAttributes, &maxAttributes);
			return std::vector<bool>(maxAttributes, false);
		}
	}
}