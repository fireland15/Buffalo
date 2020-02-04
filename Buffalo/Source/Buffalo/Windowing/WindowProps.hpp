#pragma once

#include <string>

namespace Buffalo {
	namespace Windowing {
		struct WindowProps {
			const char* Title;
			unsigned int Width;
			unsigned int Height;

			WindowProps(const char* title = "Buffalo Engine",
				unsigned int width = 720,
				unsigned int height = 720)
				: Title(title), Width(width), Height(height) { }
		};
	}
}