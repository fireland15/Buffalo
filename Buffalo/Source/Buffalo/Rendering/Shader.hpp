#pragma once

#include <vector>
#include <string>
#include <Buffalo/Rendering/GL.hpp>
#include <Buffalo/Rendering/ShaderType.hpp>

namespace Buffalo {
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