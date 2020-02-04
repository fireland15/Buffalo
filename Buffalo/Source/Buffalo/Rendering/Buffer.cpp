#include <Buffalo/Rendering/Buffer.hpp>
#include <Buffalo/Core/Debug.hpp>
#include <Buffalo/Rendering/GL.hpp>

namespace Buffalo {
	namespace Rendering {
		Buffer::Buffer() {
			BUFFALO_PROFILE_FUNC();
			GL::GenBuffers(1, &_handle);
		}

		Buffer::~Buffer() {
			BUFFALO_PROFILE_FUNC();
			GL::DeleteBuffers(1, &_handle);
		}

		void Buffer::Bind(BufferTarget target) {
			BUFFALO_PROFILE_FUNC();
			GL::BindBuffer(target, _handle);
			_target = target;
		}

		bool Buffer::IsBound() const {
			BUFFALO_PROFILE_FUNC();
			GLint currentBuffer = 0;
			switch (_target) {
			case BufferTarget::ArrayBuffer: {
				GL::GetIntegerv(ParameterName::ArrayBufferBinding, &currentBuffer);
				break;
			}
			case BufferTarget::ElementArrayBuffer: {
				GL::GetIntegerv(ParameterName::ElementArrayBufferBinding, &currentBuffer);
				break;
			}
			default: {
				throw std::runtime_error("Invalid enum value");
			}
			}
			return currentBuffer == static_cast<GLint>(_handle);
		}

		void Buffer::Reserve(GLsizeiptr size, BufferUsage usage) {
			if (!IsBound()) {
				throw std::runtime_error("Attempting to call GL::BufferData without binding the buffer to a target.");
			}
			GL::BufferData(_target, size, nullptr, usage);
		}

		void Buffer::SetData(const void* data, GLsizeiptr bytes) {
			if (!IsBound()) {
				throw std::runtime_error("Attempting to call GL::BufferSubData without binding the buffer to a target.");
			}
			if (bytes > Size()) {
				throw std::runtime_error("Attempting to write too much to the buffer.");
			}
			GL::BufferSubData(_target, 0, bytes, data);
		}

		GLint Buffer::Size() const {
			GLint data;
			GL::GetBufferParameteriv(_target, BufferParameterName::Size, &data);
			return static_cast<std::size_t>(data);
		}
		
		void Buffer::Unbind() {
			GL::BindBuffer(_target, 0U);
			_target = BufferTarget::NoTarget;
		}

		GLuint Buffer::Handle() const {
			return _handle;
		}
		
		bool operator<(const Buffer& lhs, const Buffer& rhs) {
			return lhs.Handle() < rhs.Handle();
		}
	}
}