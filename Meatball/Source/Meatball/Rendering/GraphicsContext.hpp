#pragma once

struct GLFWwindow;

namespace Meatball {
	namespace Rendering {
		class GraphicsContext {
		public:
			GraphicsContext(GLFWwindow* window);
			
			void Init();

			void SwapBuffers();

		private:
			GLFWwindow* window;
		};
	}
}