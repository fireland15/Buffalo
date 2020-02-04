#include <Buffalo/Rendering/Shader.hpp>
#include <stdexcept>
#include <Buffalo/Rendering/Status.hpp>
#include <Buffalo/Core/Debug.hpp>

namespace Buffalo {
	namespace Rendering {
		Shader::Shader(ShaderType type)
			: Type(type), handle(GL::CreateShader(type)) { 
			BUFFALO_PROFILE_FUNC();
		}

		Shader::~Shader() {
			BUFFALO_PROFILE_FUNC();
		}

		void Shader::AddSource(std::string& source) {
			BUFFALO_PROFILE_FUNC();
			assert(source.length() > 0); // The sources cannot be empty.
			sources.push_back(source);

			GLint length = static_cast<GLint>(source.length());
			const char* str = source.c_str();

			GL::ShaderSource(handle, 1, &str, &length);
		}
		
		void Shader::Compile() {
			BUFFALO_PROFILE_FUNC();
			assert(sources.size() > 0); // can't compile because there's nothing to compile!
			GL::CompileShader(handle);
			if (!IsCompiled()) {
				auto infoLog = InfoLog();
				BUFFALO_LOG_ERROR(infoLog);
				throw std::runtime_error(infoLog);
			}
		}
		
		GLuint Shader::Handle() const {
			BUFFALO_PROFILE_FUNC();
			return handle;
		}
		
		bool Shader::IsCompiled() const {
			BUFFALO_PROFILE_FUNC();
			GLint status = 0;
			GL::GetShaderiv(handle, ShaderParameterName::CompileStatus, &status);
			return static_cast<Status>(status) == Status::Success;
		}
		
		std::string Shader::InfoLog() {
			BUFFALO_PROFILE_FUNC();
			GLint length = 0;
			GL::GetShaderiv(handle, ShaderParameterName::InfoLogLength, &length);
			std::string infoLog(length, ' ');
			GL::GetShaderInfoLog(handle, length, nullptr, &infoLog[0]);
			return infoLog;
		}
	}
}