#pragma once

#include <glad/glad.h>
#include <Buffalo/Rendering/BufferTarget.hpp>
#include <Buffalo/Rendering/BufferUsage.hpp>

namespace Buffalo {
	namespace Rendering {
		class Buffer {
		public:
			Buffer();
			Buffer(const Buffer& other) = delete;
			Buffer(Buffer&& other) = delete;
			Buffer& operator=(const Buffer& other) = delete;
			Buffer& operator=(Buffer&& other) = delete;
			~Buffer();

			void Bind(BufferTarget target);
			bool IsBound() const;
			void Reserve(GLsizeiptr size, BufferUsage usage);
			void SetData(const void* data, GLsizeiptr bytes);
			GLint Size() const;
			void Unbind();
			GLuint Handle() const;

			friend bool operator<(const Buffer& lhs, const Buffer& rhs);

		private:
			BufferTarget _target = BufferTarget::NoTarget;
			GLuint _handle = 0U;
		};
	}
}