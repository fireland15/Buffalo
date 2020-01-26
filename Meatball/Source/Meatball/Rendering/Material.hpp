#pragma once

#include <glm/glm.hpp>

namespace Meatball {
	namespace Rendering {
		class Program;
		struct UniformVariable;

		class Material {
		public:
			Material(const glm::vec4& color, Program& program);

			void PreDraw();

			void PostDraw();

		private:
			glm::vec4 color;

			const UniformVariable& colorUniform;

			Program& program;
		};
	}
}