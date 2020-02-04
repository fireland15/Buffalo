#include <Buffalo/Rendering/GL.hpp>
#include <Buffalo/Core/Debug.hpp>

#ifdef BUFFALO_DEBUG
#define BUFFALO_CHECK_OPENGL_ERROR() GL::GetError()
#endif
#ifndef BUFFALO_DEBUG
#define BUFFALO_CHECK_OPENGL_ERROR() void(0);
#endif

namespace Buffalo {
	namespace Rendering {
		void GL::AttachShader(GLuint program, GLuint shader) {
			BUFFALO_PROFILE_FUNC();
			glAttachShader(program, shader);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::BindBuffer(BufferTarget target, GLuint buffer) {
			BUFFALO_PROFILE_FUNC();
			glBindBuffer(static_cast<GLenum>(target), buffer);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::BindTexture(TextureTarget target, GLuint texture) {
			BUFFALO_PROFILE_FUNC();
			glBindTexture(static_cast<GLenum>(target), texture);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::BindVertexArray(GLuint vao) {
			BUFFALO_PROFILE_FUNC();
			glBindVertexArray(vao);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::BufferData(BufferTarget target, GLsizeiptr size, const GLvoid* pData, BufferUsage usage) {
			BUFFALO_PROFILE_FUNC();
			glBufferData(static_cast<GLenum>(target), size, pData, static_cast<GLenum>(usage));
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::BufferSubData(BufferTarget target, GLintptr offset, GLsizeiptr size, const GLvoid* data) {
			BUFFALO_PROFILE_FUNC();
			glBufferSubData(static_cast<GLenum>(target), offset, size, data);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::Clear(GLbitfield mask) {
			BUFFALO_PROFILE_FUNC();
			glClear(mask);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::ClearColor(glm::vec4 color) {
			BUFFALO_PROFILE_FUNC();
			glClearColor(color.r, color.g, color.b, color.a);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::CompileShader(GLuint shader) {
			BUFFALO_PROFILE_FUNC();
			glCompileShader(shader);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		GLuint GL::CreateProgram() {
			BUFFALO_PROFILE_FUNC();
			auto result = glCreateProgram();
			BUFFALO_CHECK_OPENGL_ERROR();
			return result;
		}

		GLuint GL::CreateShader(ShaderType shaderType) {
			BUFFALO_PROFILE_FUNC();
			auto result = glCreateShader(static_cast<GLenum>(shaderType));
			BUFFALO_CHECK_OPENGL_ERROR();
			return result;
		}

		void GL::DeleteBuffers(GLsizei n, const GLuint* buffer) {
			BUFFALO_PROFILE_FUNC();
			glDeleteBuffers(n, buffer);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::DeleteProgram(GLuint program) {
			BUFFALO_PROFILE_FUNC();
			glDeleteProgram(program);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::DeleteShader(GLuint shader) {
			BUFFALO_PROFILE_FUNC();
			glDeleteShader(shader);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::DeleteTextures(GLsizei n, const GLuint* textures) {
			BUFFALO_PROFILE_FUNC();
			glDeleteTextures(n, textures);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::DeleteVertexArrays(GLsizei n, const GLuint* vao) {
			BUFFALO_PROFILE_FUNC();
			glDeleteVertexArrays(n, vao);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::DetachShader(GLuint program, GLuint shader) {
			BUFFALO_PROFILE_FUNC();
			glDetachShader(program, shader);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::DisableVertexAttribArray(GLuint index) {
			BUFFALO_PROFILE_FUNC();
			glDisableVertexAttribArray(index);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::DrawArrays(PrimitiveDrawMode mode, GLint first, GLsizei count) {
			BUFFALO_PROFILE_FUNC();
			glDrawArrays(static_cast<GLenum>(mode), first, count);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::DrawElements(PrimitiveDrawMode mode, GLsizei count, IndicesDataType type, const GLvoid* indices) {
			BUFFALO_PROFILE_FUNC();
			glDrawElements(static_cast<GLenum>(mode), count, static_cast<GLenum>(type), indices);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::Enable(Capability cap) {
			BUFFALO_PROFILE_FUNC();
			glEnable(static_cast<GLenum>(cap));
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::EnableVertexAttribArray(GLuint index) {
			BUFFALO_PROFILE_FUNC();
			glEnableVertexAttribArray(index);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::Flush() {
			BUFFALO_PROFILE_FUNC();
			glFlush();
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::GenBuffers(GLsizei n, GLuint* pBuffers) {
			BUFFALO_PROFILE_FUNC();
			glGenBuffers(n, pBuffers);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::GenTextures(GLsizei n, GLuint* textures) {
			BUFFALO_PROFILE_FUNC();
			glGenTextures(n, textures);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::GenVertexArrays(GLsizei n, GLuint* pVaos) {
			BUFFALO_PROFILE_FUNC();
			glGenVertexArrays(n, pVaos);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, AttributeDataType* type, GLchar* name) {
			BUFFALO_PROFILE_FUNC();
			glGetActiveAttrib(program, index, bufSize, length, size, static_cast<GLenum*>(static_cast<void*>(type)), name);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, UniformDataType* type, GLchar* name) {
			BUFFALO_PROFILE_FUNC();
			glGetActiveUniform(program, index, bufSize, length, size, static_cast<GLenum*>(static_cast<void*>(type)), name);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		GLint GL::GetAttribLocation(GLuint program, const GLchar* name) {
			BUFFALO_PROFILE_FUNC();
			auto result = glGetAttribLocation(program, name);
			BUFFALO_CHECK_OPENGL_ERROR();
			return result;
		}

		void GL::GetBufferParameteriv(BufferTarget target, BufferParameterName pname, GLint* data) {
			BUFFALO_PROFILE_FUNC();
			glGetBufferParameteriv(static_cast<GLenum>(target), static_cast<GLenum>(pname), data);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		GLenum GL::GetError() {
			BUFFALO_PROFILE_FUNC();
			auto result = glGetError();

			if (result != GL_NO_ERROR) {
				BUFFALO_LOG_INFO(result);
				throw std::runtime_error("OpenGL Error");
			}

			return result;
		}

		void GL::GetIntegerv(ParameterName pname, GLint* data) {
			BUFFALO_PROFILE_FUNC();
			glGetIntegerv(static_cast<GLenum>(pname), data);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::GetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei* length, GLchar* infoLog) {
			BUFFALO_PROFILE_FUNC();
			glGetProgramInfoLog(program, maxLength, length, infoLog);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::GetProgramiv(GLuint program, ProgramParameterName pname, GLint* params) {
			BUFFALO_PROFILE_FUNC();
			glGetProgramiv(program, static_cast<GLenum>(pname), params);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		const GLubyte* GL::GetString(StringName name) {
			BUFFALO_PROFILE_FUNC();
			auto result = glGetString(static_cast<GLenum>(name));
			BUFFALO_CHECK_OPENGL_ERROR();
			return result;
		}

		GLint GL::GetUniformLocation(GLuint program, const GLchar* name) {
			BUFFALO_PROFILE_FUNC();
			auto result = glGetUniformLocation(program, name);
			BUFFALO_CHECK_OPENGL_ERROR();
			return result;
		}

		void GL::LinkProgram(GLuint program) {
			BUFFALO_PROFILE_FUNC();
			glLinkProgram(program);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::GetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog) {
			BUFFALO_PROFILE_FUNC();
			glGetShaderInfoLog(shader, maxLength, length, infoLog);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::GetShaderiv(GLuint shader, ShaderParameterName pname, GLint* params) {
			BUFFALO_PROFILE_FUNC();
			glGetShaderiv(shader, static_cast<GLenum>(pname), params);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::ProgramUniform3f(GLuint program, GLint location, glm::vec3& v) {
			BUFFALO_PROFILE_FUNC();
			glProgramUniform3f(program, location, v[0], v[1], v[2]);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::ProgramUniform4f(GLuint program, GLint location, glm::vec4& v) {
			BUFFALO_PROFILE_FUNC();
			glProgramUniform4f(program, location, v[0], v[1], v[2], v[3]);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::ProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
			BUFFALO_PROFILE_FUNC();
			glProgramUniformMatrix4fv(program, location, count, transpose, value);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::ShaderSource(GLuint shader, GLsizei count, const GLchar** string, const GLint* length) {
			BUFFALO_PROFILE_FUNC();
			glShaderSource(shader, count, string, length);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::TexImage2D(TextureTarget target, GLint level, TextureInternalFormat internalFormat, GLsizei width, GLsizei height, PixelFormat format, PixelDataType type, const GLvoid* data) {
			BUFFALO_PROFILE_FUNC();
			glTexImage2D(static_cast<GLenum>(target), level, static_cast<GLint>(internalFormat), width, height, 0, static_cast<GLenum>(format), static_cast<GLenum>(type), data);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::TexParameteri(TextureTarget target, TextureParameterName pname, GLint param) {
			BUFFALO_PROFILE_FUNC();
			glTexParameteri(static_cast<GLenum>(target), static_cast<GLenum>(pname), param);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::UseProgram(GLuint program) {
			BUFFALO_PROFILE_FUNC();
			glUseProgram(program);
			BUFFALO_CHECK_OPENGL_ERROR();
		}

		void GL::VertexAttribPointer(GLuint index, GLint size, AttributeDataType type, GLboolean normalized, GLsizei stride, const GLvoid* pointer) {
			BUFFALO_PROFILE_FUNC();
			glVertexAttribPointer(index, size, static_cast<GLenum>(type), normalized, stride, pointer);
			BUFFALO_CHECK_OPENGL_ERROR();
		}
	}
}