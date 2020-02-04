#include <Buffalo/Rendering/Material.hpp>
#include <Buffalo/Rendering/Program.hpp>
#include <Buffalo/Rendering/UniformVariable.hpp>
#include <Buffalo/Core/Debug.hpp>

static std::string colorUniformName("u_color");

namespace Buffalo {
	namespace Rendering {
		Material::Material(const glm::vec4& color, Rendering::Program& program)
			: color(color)
			, Program(program)
			, colorUniform(program.GetUniform(colorUniformName)) {
			BUFFALO_PROFILE_FUNC();
		}

		void Material::PreDraw() {
			BUFFALO_PROFILE_FUNC();
			Program.Use();
			Program.SetUniform(colorUniform, color);
		}

		void Material::PostDraw() {
			BUFFALO_PROFILE_FUNC();
		}
	}
}