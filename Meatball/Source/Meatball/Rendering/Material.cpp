#include <Meatball/Rendering/Material.hpp>
#include <Meatball/Rendering/Program.hpp>
#include <Meatball/Rendering/UniformVariable.hpp>
#include <Meatball/Core/Debug.hpp>

namespace Meatball {
	namespace Rendering {
		Material::Material(const glm::vec4& color, Rendering::Program& program)
			: color(color)
			, program(program)
			, colorUniform(program.GetUniform("u_color")) {
			MEATBALL_PROFILE_FUNC();
		}

		void Material::PreDraw() {
			MEATBALL_PROFILE_FUNC();
			program.Use();
			program.SetUniform(colorUniform, color);
		}

		void Material::PostDraw() {
			MEATBALL_PROFILE_FUNC();
		}
	}
}