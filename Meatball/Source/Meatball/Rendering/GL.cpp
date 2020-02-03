#include <Meatball/Rendering/GL.hpp>
#include <Meatball/Core/Debug.hpp>

#ifdef MEATBALL_DEBUG
#define MEATBALL_CHECK_OPENGL_ERROR() GL::GetError()
#endif
#ifndef MEATBALL_DEBUG
#define MEATBALL_CHECK_OPENGL_ERROR() void(0);
#endif

namespace Meatball {
	namespace Rendering {
		void GL::AttachShader(GLuint program, GLuint shader) {
			MEATBALL_PROFILE_FUNC();
			glAttachShader(program, shader);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::BindBuffer(BufferTarget target, GLuint buffer) {
			MEATBALL_PROFILE_FUNC();
			glBindBuffer(static_cast<GLenum>(target), buffer);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::BindTexture(TextureTarget target, GLuint texture) {
			MEATBALL_PROFILE_FUNC();
			glBindTexture(static_cast<GLenum>(target), texture);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::BindVertexArray(GLuint vao) {
			MEATBALL_PROFILE_FUNC();
			glBindVertexArray(vao);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::BufferData(BufferTarget target, GLsizeiptr size, const GLvoid* pData, BufferUsage usage) {
			MEATBALL_PROFILE_FUNC();
			glBufferData(static_cast<GLenum>(target), size, pData, static_cast<GLenum>(usage));
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::BufferSubData(BufferTarget target, GLintptr offset, GLsizeiptr size, const GLvoid* data) {
			MEATBALL_PROFILE_FUNC();
			glBufferSubData(static_cast<GLenum>(target), offset, size, data);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::Clear(GLbitfield mask) {
			MEATBALL_PROFILE_FUNC();
			glClear(mask);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::ClearColor(glm::vec4 color) {
			MEATBALL_PROFILE_FUNC();
			glClearColor(color.r, color.g, color.b, color.a);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::CompileShader(GLuint shader) {
			MEATBALL_PROFILE_FUNC();
			glCompileShader(shader);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		GLuint GL::CreateProgram() {
			MEATBALL_PROFILE_FUNC();
			auto result = glCreateProgram();
			MEATBALL_CHECK_OPENGL_ERROR();
			return result;
		}

		GLuint GL::CreateShader(ShaderType shaderType) {
			MEATBALL_PROFILE_FUNC();
			auto result = glCreateShader(static_cast<GLenum>(shaderType));
			MEATBALL_CHECK_OPENGL_ERROR();
			return result;
		}

		void GL::DeleteBuffers(GLsizei n, const GLuint* buffer) {
			MEATBALL_PROFILE_FUNC();
			glDeleteBuffers(n, buffer);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::DeleteProgram(GLuint program) {
			MEATBALL_PROFILE_FUNC();
			glDeleteProgram(program);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::DeleteShader(GLuint shader) {
			MEATBALL_PROFILE_FUNC();
			glDeleteShader(shader);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::DeleteTextures(GLsizei n, const GLuint* textures) {
			MEATBALL_PROFILE_FUNC();
			glDeleteTextures(n, textures);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::DeleteVertexArrays(GLsizei n, const GLuint* vao) {
			MEATBALL_PROFILE_FUNC();
			glDeleteVertexArrays(n, vao);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::DetachShader(GLuint program, GLuint shader) {
			MEATBALL_PROFILE_FUNC();
			glDetachShader(program, shader);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::DisableVertexAttribArray(GLuint index) {
			MEATBALL_PROFILE_FUNC();
			glDisableVertexAttribArray(index);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::DrawArrays(PrimitiveDrawMode mode, GLint first, GLsizei count) {
			MEATBALL_PROFILE_FUNC();
			glDrawArrays(static_cast<GLenum>(mode), first, count);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::DrawElements(PrimitiveDrawMode mode, GLsizei count, IndicesDataType type, const GLvoid* indices) {
			MEATBALL_PROFILE_FUNC();
			glDrawElements(static_cast<GLenum>(mode), count, static_cast<GLenum>(type), indices);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::Enable(Capability cap) {
			MEATBALL_PROFILE_FUNC();
			glEnable(static_cast<GLenum>(cap));
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::EnableVertexAttribArray(GLuint index) {
			MEATBALL_PROFILE_FUNC();
			glEnableVertexAttribArray(index);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::Flush() {
			MEATBALL_PROFILE_FUNC();
			glFlush();
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::GenBuffers(GLsizei n, GLuint* pBuffers) {
			MEATBALL_PROFILE_FUNC();
			glGenBuffers(n, pBuffers);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::GenTextures(GLsizei n, GLuint* textures) {
			MEATBALL_PROFILE_FUNC();
			glGenTextures(n, textures);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::GenVertexArrays(GLsizei n, GLuint* pVaos) {
			MEATBALL_PROFILE_FUNC();
			glGenVertexArrays(n, pVaos);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, AttributeDataType* type, GLchar* name) {
			MEATBALL_PROFILE_FUNC();
			glGetActiveAttrib(program, index, bufSize, length, size, static_cast<GLenum*>(static_cast<void*>(type)), name);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, UniformDataType* type, GLchar* name) {
			MEATBALL_PROFILE_FUNC();
			glGetActiveUniform(program, index, bufSize, length, size, static_cast<GLenum*>(static_cast<void*>(type)), name);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		GLint GL::GetAttribLocation(GLuint program, const GLchar* name) {
			MEATBALL_PROFILE_FUNC();
			auto result = glGetAttribLocation(program, name);
			MEATBALL_CHECK_OPENGL_ERROR();
			return result;
		}

		void GL::GetBufferParameteriv(BufferTarget target, BufferParameterName pname, GLint* data) {
			MEATBALL_PROFILE_FUNC();
			glGetBufferParameteriv(static_cast<GLenum>(target), static_cast<GLenum>(pname), data);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		GLenum GL::GetError() {
			MEATBALL_PROFILE_FUNC();
			auto result = glGetError();

			if (result != GL_NO_ERROR) {
				MEATBALL_LOG_INFO(result);
				throw std::runtime_error("OpenGL Error");
			}

			return result;
		}

		void GL::GetIntegerv(ParameterName pname, GLint* data) {
			MEATBALL_PROFILE_FUNC();
			glGetIntegerv(static_cast<GLenum>(pname), data);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::GetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei* length, GLchar* infoLog) {
			MEATBALL_PROFILE_FUNC();
			glGetProgramInfoLog(program, maxLength, length, infoLog);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::GetProgramiv(GLuint program, ProgramParameterName pname, GLint* params) {
			MEATBALL_PROFILE_FUNC();
			glGetProgramiv(program, static_cast<GLenum>(pname), params);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		const GLubyte* GL::GetString(StringName name) {
			MEATBALL_PROFILE_FUNC();
			auto result = glGetString(static_cast<GLenum>(name));
			MEATBALL_CHECK_OPENGL_ERROR();
			return result;
		}

		GLint GL::GetUniformLocation(GLuint program, const GLchar* name) {
			MEATBALL_PROFILE_FUNC();
			auto result = glGetUniformLocation(program, name);
			MEATBALL_CHECK_OPENGL_ERROR();
			return result;
		}

		void GL::LinkProgram(GLuint program) {
			MEATBALL_PROFILE_FUNC();
			glLinkProgram(program);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::GetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog) {
			MEATBALL_PROFILE_FUNC();
			glGetShaderInfoLog(shader, maxLength, length, infoLog);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::GetShaderiv(GLuint shader, ShaderParameterName pname, GLint* params) {
			MEATBALL_PROFILE_FUNC();
			glGetShaderiv(shader, static_cast<GLenum>(pname), params);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::ProgramUniform3f(GLuint program, GLint location, glm::vec3& v) {
			MEATBALL_PROFILE_FUNC();
			glProgramUniform3f(program, location, v[0], v[1], v[2]);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::ProgramUniform4f(GLuint program, GLint location, glm::vec4& v) {
			MEATBALL_PROFILE_FUNC();
			glProgramUniform4f(program, location, v[0], v[1], v[2], v[3]);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::ProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
			MEATBALL_PROFILE_FUNC();
			glProgramUniformMatrix4fv(program, location, count, transpose, value);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::ShaderSource(GLuint shader, GLsizei count, const GLchar** string, const GLint* length) {
			MEATBALL_PROFILE_FUNC();
			glShaderSource(shader, count, string, length);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::TexImage2D(TextureTarget target, GLint level, TextureInternalFormat internalFormat, GLsizei width, GLsizei height, PixelFormat format, PixelDataType type, const GLvoid* data) {
			MEATBALL_PROFILE_FUNC();
			glTexImage2D(static_cast<GLenum>(target), level, static_cast<GLint>(internalFormat), width, height, 0, static_cast<GLenum>(format), static_cast<GLenum>(type), data);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::TexParameteri(TextureTarget target, TextureParameterName pname, GLint param) {
			MEATBALL_PROFILE_FUNC();
			glTexParameteri(static_cast<GLenum>(target), static_cast<GLenum>(pname), param);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::UseProgram(GLuint program) {
			MEATBALL_PROFILE_FUNC();
			glUseProgram(program);
			MEATBALL_CHECK_OPENGL_ERROR();
		}

		void GL::VertexAttribPointer(GLuint index, GLint size, AttributeDataType type, GLboolean normalized, GLsizei stride, const GLvoid* pointer) {
			MEATBALL_PROFILE_FUNC();
			glVertexAttribPointer(index, size, static_cast<GLenum>(type), normalized, stride, pointer);
			MEATBALL_CHECK_OPENGL_ERROR();
		}
	}
}