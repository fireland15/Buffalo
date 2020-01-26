#pragma once

#include <vector>
#include <string>
#include <Meatball/Rendering/GL.hpp>
#include <Meatball/Rendering/ShaderType.hpp>

namespace Meatball {
	namespace Rendering {
		class Shader {
		public:
			Shader(ShaderType type);
			Shader(const Shader& other) = delete;
			Shader(Shader&& other) = delete;
			Shader& operator=(const Shader& other) = delete;
			Shader& operator=(Shader&& other) = delete;
			~Shader();

			void AddSource(std::string& source);
			void Compile();
			GLuint Handle() const;
			bool IsCompiled() const;
			std::string InfoLog();

		public:
			const ShaderType Type;

		private:
			GLuint handle = 0U;
			std::vector<std::string> sources;
		};
	}
}