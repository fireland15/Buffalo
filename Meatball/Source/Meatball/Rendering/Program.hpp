#pragma once

#include <map>
#include <glm/glm.hpp>
#include <Meatball/Rendering/GL.hpp>
#include <Meatball/Rendering/AttributeVariable.hpp>
#include <Meatball/Rendering/UniformVariable.hpp>

namespace Meatball {
	namespace Rendering {
		class Shader;

		class Program {
		public:
			Program();
			Program(const Program& other) = delete;
			Program(Program&& other) = delete;
			Program& operator=(const Program& other) = delete;
			Program& operator=(Program&& other) = delete;
			~Program();

			void AttachShader(Shader& shader);
			const AttributeVariable& GetAttribute(const char* name);
			const UniformVariable& GetUniform(const char* name);
			void DetachShader(Shader& shader);
			std::string GetInfoLog();
			inline GLuint Handle() const { return handle; }
			bool IsLinked();
			bool IsUsed() const;
			void Link();
			void SetUniform(const UniformVariable& uniform, glm::vec4& v);
			void SetUniform(const UniformVariable& uniform, glm::mat4& v);
			void Use();

		private:
			GLuint handle = 0U;
			std::map<const char*, AttributeVariable> attributes;
			std::map<const char*, UniformVariable> uniforms;

			void RefreshAttributes();
			void RefreshUniforms();
		};
	}
}