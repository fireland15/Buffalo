#include <Meatball/Rendering/Material.hpp>
#include <Meatball/Rendering/Program.hpp>
#include <Meatball/Rendering/UniformVariable.hpp>
#include <Meatball/Core/Debug.hpp>

static std::string colorUniformName("u_color");

namespace Meatball {
	namespace Rendering {
		Material::Material(const glm::vec4& color, Rendering::Program& program)
			: color(color)
			, Program(program)
			, colorUniform(program.GetUniform(colorUniformName)) {
			MEATBALL_PROFILE_FUNC();
		}

		void Material::PreDraw() {
			MEATBALL_PROFILE_FUNC();
			Program.Use();
			Program.SetUniform(colorUniform, color);
		}

		void Material::PostDraw() {
			MEATBALL_PROFILE_FUNC();
		}
	}
}