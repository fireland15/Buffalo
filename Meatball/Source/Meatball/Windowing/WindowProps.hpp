#pragma once

#include <string>

namespace Meatball {
	namespace Windowing {
		struct WindowProps {
			const char* Title;
			unsigned int Width;
			unsigned int Height;

			WindowProps(const char* title = "Meatball Engine",
				unsigned int width = 720,
				unsigned int height = 720)
				: Title(title), Width(width), Height(height) { }
		};
	}
}