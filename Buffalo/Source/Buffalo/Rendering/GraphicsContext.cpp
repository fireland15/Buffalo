#include <Buffalo/Rendering/GraphicsContext.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Buffalo/Core/Debug.hpp>
#include <gl/GL.h>

namespace Buffalo {
	namespace Rendering {
		GraphicsContext::GraphicsContext(GLFWwindow* window) 
			: window(window) { }

		void GraphicsContext::Init() {
			BUFFALO_PROFILE_FUNC();

			glfwMakeContextCurrent(window);
			int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
			if (!status) {
				BUFFALO_LOG_ERROR("Failed to initialize OpenGL context. GLAD loaded failed.");
				throw std::runtime_error("Failed to initialize OpenGL context. GLAD loaded failed.");
			}

			BUFFALO_LOG_INFO("Initialized OpenGL context with GLFW window.");

			BUFFALO_LOG_INFO("OpenGL Info:");
			BUFFALO_LOG_INFO("\tVendor: {}", glGetString(GL_VENDOR));
			BUFFALO_LOG_INFO("\tRenderer: {}", glGetString(GL_RENDERER));
			BUFFALO_LOG_INFO("\tVersion: {}", glGetString(GL_VERSION));
		}

		void GraphicsContext::SwapBuffers() {
			glfwSwapBuffers(window);
		}
	}
}