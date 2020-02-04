#pragma once

struct GLFWwindow;

namespace Buffalo {
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