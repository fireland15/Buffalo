#pragma once

#include <Meatball/Rendering/GraphicsContext.hpp>

struct GLFWwindow;

namespace Meatball {
	namespace OpenGL {
		class OpenGLGraphicsContext : Rendering::GraphicsContext {
		public:

			OpenGLGraphicsContext(GLFWwindow* window);

			virtual void Init() override;

			virtual void SwapBuffers() override;

		private:

			GLFWwindow* _window;

		};
	}
}