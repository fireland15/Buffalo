#include <Meatball/Rendering/GL.hpp>
#include <Meatball/Core/Debug.hpp>

namespace Meatball {
	namespace Rendering {
		void GL::AttachShader(GLuint program, GLuint shader) {
			MEATBALL_PROFILE_FUNC();
			glAttachShader(program, shader);
		}

		void GL::BindBuffer(BufferTarget target, GLuint buffer) {
			MEATBALL_PROFILE_FUNC();
			glBindBuffer(static_cast<GLenum>(target), buffer);
		}

		void GL::BindTexture(TextureTarget target, GLuint texture) {
			MEATBALL_PROFILE_FUNC();
			glBindTexture(static_cast<GLenum>(target), texture);
		}

		void GL::BindVertexArray(GLuint vao) {
			MEATBALL_PROFILE_FUNC();
			glBindVertexArray(vao);
		}

		void GL::BufferData(BufferTarget target, GLsizeiptr size, const GLvoid* pData, BufferUsage usage) {
			MEATBALL_PROFILE_FUNC();
			glBufferData(static_cast<GLenum>(target), size, pData, static_cast<GLenum>(usage));
		}

		void GL::BufferSubData(BufferTarget target, GLintptr offset, GLsizeiptr size, const GLvoid* data) {
			MEATBALL_PROFILE_FUNC();
			glBufferSubData(static_cast<GLenum>(target), offset, size, data);
		}

		void GL::Clear(GLbitfield mask) {
			MEATBALL_PROFILE_FUNC();
			glClear(mask);
		}

		void GL::ClearColor(glm::vec4 color) {
			MEATBALL_PROFILE_FUNC();
			glClearColor(color.r, color.g, color.b, color.a);
		}

		void GL::CompileShader(GLuint shader) {
			MEATBALL_PROFILE_FUNC();
			glCompileShader(shader);
		}

		GLuint GL::CreateProgram() {
			MEATBALL_PROFILE_FUNC();
			return glCreateProgram();
		}

		GLuint GL::CreateShader(ShaderType shaderType) {
			MEATBALL_PROFILE_FUNC();
			return glCreateShader(static_cast<GLenum>(shaderType));
		}

		void GL::DeleteBuffers(GLsizei n, const GLuint* buffer) {
			MEATBALL_PROFILE_FUNC();
			glDeleteBuffers(n, buffer);
		}

		void GL::DeleteProgram(GLuint program) {
			MEATBALL_PROFILE_FUNC();
			glDeleteProgram(program);
		}

		void GL::DeleteShader(GLuint shader) {
			MEATBALL_PROFILE_FUNC();
			glDeleteShader(shader);
		}

		void GL::DeleteTextures(GLsizei n, const GLuint* textures) {
			MEATBALL_PROFILE_FUNC();
			glDeleteTextures(n, textures);
		}

		void GL::DeleteVertexArrays(GLsizei n, const GLuint* vao) {
			MEATBALL_PROFILE_FUNC();
			glDeleteVertexArrays(n, vao);
		}

		void GL::DetachShader(GLuint program, GLuint shader) {
			MEATBALL_PROFILE_FUNC();
			glDetachShader(program, shader);
		}

		void GL::DisableVertexAttribArray(GLuint index) {
			MEATBALL_PROFILE_FUNC();
			glDisableVertexAttribArray(index);
		}

		void GL::DrawArrays(PrimitiveDrawMode mode, GLint first, GLsizei count) {
			MEATBALL_PROFILE_FUNC();
			glDrawArrays(static_cast<GLenum>(mode), first, count);
		}

		void GL::DrawElements(PrimitiveDrawMode mode, GLsizei count, IndicesDataType type, const GLvoid* indices) {
			MEATBALL_PROFILE_FUNC();
			glDrawElements(static_cast<GLenum>(mode), count, static_cast<GLenum>(type), indices);
		}

		void GL::Enable(Capability cap) {
			MEATBALL_PROFILE_FUNC();
			glEnable(static_cast<GLenum>(cap));
		}

		void GL::EnableVertexAttribArray(GLuint index) {
			MEATBALL_PROFILE_FUNC();
			glEnableVertexAttribArray(index);
		}

		void GL::Flush() {
			MEATBALL_PROFILE_FUNC();
			glFlush();
		}

		void GL::GenBuffers(GLsizei n, GLuint* pBuffers) {
			MEATBALL_PROFILE_FUNC();
			glGenBuffers(n, pBuffers);
		}

		void GL::GenTextures(GLsizei n, GLuint* textures) {
			MEATBALL_PROFILE_FUNC();
			glGenTextures(n, textures);
		}

		void GL::GenVertexArrays(GLsizei n, GLuint* pVaos) {
			MEATBALL_PROFILE_FUNC();
			glGenVertexArrays(n, pVaos);
		}

		void GL::GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, AttributeDataType* type, GLchar* name) {
			MEATBALL_PROFILE_FUNC();
			glGetActiveAttrib(program, index, bufSize, length, size, static_cast<GLenum*>(static_cast<void*>(type)), name);
		}

		void GL::GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, UniformDataType* type, GLchar* name) {
			MEATBALL_PROFILE_FUNC();
			glGetActiveUniform(program, index, bufSize, length, size, static_cast<GLenum*>(static_cast<void*>(type)), name);
		}

		GLint GL::GetAttribLocation(GLuint program, const GLchar* name) {
			MEATBALL_PROFILE_FUNC();
			return glGetAttribLocation(program, name);
		}

		void GL::GetBufferParameteriv(BufferTarget target, BufferParameterName pname, GLint* data) {
			MEATBALL_PROFILE_FUNC();
			glGetBufferParameteriv(static_cast<GLenum>(target), static_cast<GLenum>(pname), data);
		}

		GLenum GL::GetError() {
			MEATBALL_PROFILE_FUNC();
			return glGetError();
		}

		void GL::GetIntegerv(ParameterName pname, GLint* data) {
			MEATBALL_PROFILE_FUNC();
			glGetIntegerv(static_cast<GLenum>(pname), data);
		}

		void GL::GetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei* length, GLchar* infoLog) {
			MEATBALL_PROFILE_FUNC();
			glGetProgramInfoLog(program, maxLength, length, infoLog);
		}

		void GL::GetProgramiv(GLuint program, ProgramParameterName pname, GLint* params) {
			MEATBALL_PROFILE_FUNC();
			glGetProgramiv(program, static_cast<GLenum>(pname), params);
		}

		const GLubyte* GL::GetString(StringName name) {
			MEATBALL_PROFILE_FUNC();
			return glGetString(static_cast<GLenum>(name));
		}

		GLint GL::GetUniformLocation(GLuint program, const GLchar* name) {
			MEATBALL_PROFILE_FUNC();
			return glGetUniformLocation(program, name);
		}

		void GL::LinkProgram(GLuint program) {
			MEATBALL_PROFILE_FUNC();
			glLinkProgram(program);
		}

		void GL::GetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog) {
			MEATBALL_PROFILE_FUNC();
			glGetShaderInfoLog(shader, maxLength, length, infoLog);
		}

		void GL::GetShaderiv(GLuint shader, ShaderParameterName pname, GLint* params) {
			MEATBALL_PROFILE_FUNC();
			glGetShaderiv(shader, static_cast<GLenum>(pname), params);
		}

		void GL::ProgramUniform3f(GLuint program, GLint location, glm::vec3& v) {
			MEATBALL_PROFILE_FUNC();
			glProgramUniform3f(program, location, v[0], v[1], v[2]);
		}

		void GL::ProgramUniform4f(GLuint program, GLint location, glm::vec4& v) {
			MEATBALL_PROFILE_FUNC();
			glProgramUniform4f(program, location, v[0], v[1], v[2], v[3]);
		}

		void GL::ProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
			MEATBALL_PROFILE_FUNC();
			glProgramUniformMatrix4fv(program, location, count, transpose, value);
		}

		void GL::ShaderSource(GLuint shader, GLsizei count, const GLchar** string, const GLint* length) {
			MEATBALL_PROFILE_FUNC();
			glShaderSource(shader, count, string, length);
		}

		void GL::TexImage2D(TextureTarget target, GLint level, TextureInternalFormat internalFormat, GLsizei width, GLsizei height, PixelFormat format, PixelDataType type, const GLvoid* data) {
			MEATBALL_PROFILE_FUNC();
			glTexImage2D(static_cast<GLenum>(target), level, static_cast<GLint>(internalFormat), width, height, 0, static_cast<GLenum>(format), static_cast<GLenum>(type), data);
		}

		void GL::TexParameteri(TextureTarget target, TextureParameterName pname, GLint param) {
			MEATBALL_PROFILE_FUNC();
			glTexParameteri(static_cast<GLenum>(target), static_cast<GLenum>(pname), param);
		}

		void GL::UseProgram(GLuint program) {
			MEATBALL_PROFILE_FUNC();
			glUseProgram(program);
		}

		void GL::VertexAttribPointer(GLuint index, GLint size, AttributeDataType type, GLboolean normalized, GLsizei stride, const GLvoid* pointer) {
			MEATBALL_PROFILE_FUNC();
			glVertexAttribPointer(index, size, static_cast<GLenum>(type), normalized, stride, pointer);
		}
	}
}