#include <Buffalo/Rendering/ProgramFactory.hpp>

#include <Buffalo/Rendering/Shader.hpp>
#include <Buffalo/Rendering/Program.hpp>

namespace Buffalo {
	namespace Rendering {

		Unique<Program> ProgramFactory::CreateProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
			Buffalo::Rendering::Shader vertexShader(Buffalo::Rendering::ShaderType::Vertex);
			vertexShader.AddSource(vertexShaderSource);
			vertexShader.Compile();

			Buffalo::Rendering::Shader fragmentShader(Buffalo::Rendering::ShaderType::Fragment);
			fragmentShader.AddSource(fragmentShaderSource);
			fragmentShader.Compile();

			Unique<Program> program = std::make_unique<Buffalo::Rendering::Program>();
			program->AttachShader(vertexShader);
			program->AttachShader(fragmentShader);
			program->Link();
			program->DetachShader(vertexShader);
			program->DetachShader(fragmentShader);
			vertexShader.~Shader();
			fragmentShader.~Shader();

			return program;
		}

	}
}