#pragma once

#include <GLFW/glfw3.h>
#include <Meatball/Windowing/Window.hpp>

namespace Meatball {
	namespace Windowing {
		class GlfwWindow : public Window {
		public:
			GlfwWindow(const WindowProps & = WindowProps());

			virtual ~GlfwWindow() = default;

			virtual void AttachEventBus(Events::EventBus& eventBus) override;

		private:

		};
	}
}