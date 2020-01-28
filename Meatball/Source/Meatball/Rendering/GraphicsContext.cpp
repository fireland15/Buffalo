#include <Meatball/Rendering/GraphicsContext.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Meatball/Core/Debug.hpp>
#include <gl/GL.h>

namespace Meatball {
	namespace Rendering {
		GraphicsContext::GraphicsContext(GLFWwindow* window) 
			: window(window) { }

		void GraphicsContext::Init() {
			MEATBALL_PROFILE_FUNC();

			glfwMakeContextCurrent(window);
			int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
			if (!status) {
				MEATBALL_LOG_ERROR("Failed to initialize OpenGL context. GLAD loaded failed.");
				throw std::runtime_error("Failed to initialize OpenGL context. GLAD loaded failed.");
			}

			MEATBALL_LOG_INFO("Initialized OpenGL context with GLFW window.");

			MEATBALL_LOG_INFO("OpenGL Info:");
			MEATBALL_LOG_INFO("\tVendor: {}", glGetString(GL_VENDOR));
			MEATBALL_LOG_INFO("\tRenderer: {}", glGetString(GL_RENDERER));
			MEATBALL_LOG_INFO("\tVersion: {}", glGetString(GL_VERSION));
		}

		void GraphicsContext::SwapBuffers() {
			glfwSwapBuffers(window);
		}
	}
}