#pragma once

#include <glm/glm.hpp>
#include <Meatball/Rendering/BufferTarget.hpp>
#include <Meatball/Rendering/BufferUsage.hpp>
#include <Meatball/Rendering/BufferParameterName.hpp>
#include <Meatball/Rendering/Capability.hpp>
#include <Meatball/Rendering/TextureTarget.hpp>
#include <Meatball/Rendering/ShaderType.hpp>
#include <Meatball/Rendering/PrimitiveDrawMode.hpp>
#include <Meatball/Rendering/IndicesDataType.hpp>
#include <Meatball/Rendering/AttributeDataType.hpp>
#include <Meatball/Rendering/UniformDataType.hpp>
#include <Meatball/Rendering/ParameterName.hpp>
#include <Meatball/Rendering/ProgramParameterName.hpp>
#include <Meatball/Rendering/StringName.hpp>
#include <Meatball/Rendering/ShaderParameterName.hpp>
#include <Meatball/Rendering/TextureInternalFormat.hpp>
#include <Meatball/Rendering/TextureParameterName.hpp>
#include <Meatball/Rendering/PixelFormat.hpp>
#include <Meatball/Rendering/PixelDataType.hpp>

namespace Meatball {
    namespace Rendering {
        namespace GL {
            void AttachShader(GLuint program, GLuint shader);
            void BindBuffer(BufferTarget target, GLuint buffer);
            void BindTexture(TextureTarget target, GLuint texture);
            void BindVertexArray(GLuint vao);
            void BufferData(BufferTarget target, GLsizeiptr size, const GLvoid* pData, BufferUsage usage);
            void BufferSubData(BufferTarget target, GLintptr offset, GLsizeiptr size, const GLvoid* data);
            void Clear(GLbitfield mask);
            void ClearColor(glm::vec4 color);
            void CompileShader(GLuint shader);
            GLuint CreateProgram();
            GLuint CreateShader(ShaderType shaderType);
            void DeleteBuffers(GLsizei n, const GLuint* buffer);
            void DeleteProgram(GLuint program);
            void DeleteShader(GLuint shader);
            void DeleteTextures(GLsizei n, const GLuint* textures);
            void DeleteVertexArrays(GLsizei n, const GLuint* vao);
            void DetachShader(GLuint program, GLuint shader);
            void DisableVertexAttribArray(GLuint index);
            void DrawArrays(PrimitiveDrawMode mode, GLint first, GLsizei count);
            void DrawElements(PrimitiveDrawMode mode, GLsizei count, IndicesDataType type, const GLvoid * indices);
            void Enable(Capability cap);
            void EnableVertexAttribArray(GLuint index);
            void Flush();
            void GenBuffers(GLsizei n, GLuint* pBuffers);
            void GenTextures(GLsizei n, GLuint* textures);
            void GenVertexArrays(GLsizei n, GLuint* pVaos);
            void GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, AttributeDataType* type, GLchar* name);
            void GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, UniformDataType* type, GLchar* name);
            GLint GetAttribLocation(GLuint program, const GLchar* name);
            void GetBufferParameteriv(BufferTarget target, BufferParameterName pname, GLint* data);
            GLenum GetError();
            void GetIntegerv(ParameterName pname, GLint* data);
            void GetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei* length, GLchar* infoLog);
            void GetProgramiv(GLuint program, ProgramParameterName pname, GLint* params);
            const GLubyte* GetString(StringName name);
            GLint GetUniformLocation(GLuint program, const GLchar* name);
            void LinkProgram(GLuint program);
            void GetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog);
            void GetShaderiv(GLuint shader, ShaderParameterName pname, GLint* params);
            void ProgramUniform3f(GLuint program, GLint location, glm::vec3 & v);
            void ProgramUniform4f(GLuint program, GLint location, glm::vec4 & v);
            void ProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
            void ShaderSource(GLuint shader, GLsizei count, const GLchar** string, const GLint* length);
            void TexImage2D(TextureTarget target, GLint level, TextureInternalFormat internalFormat, GLsizei width, GLsizei height, PixelFormat format, PixelDataType type, const GLvoid* data);
            void TexParameteri(TextureTarget target, TextureParameterName pname, GLint param);
            void UseProgram(GLuint program);
            void VertexAttribPointer(GLuint index, GLint size, AttributeDataType type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
        }
    }
}