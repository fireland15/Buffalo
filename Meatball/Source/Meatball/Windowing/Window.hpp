#pragma once

#include <memory>
#include <functional>
#include <Meatball/Windowing/WindowProps.hpp>

namespace Meatball {
	namespace Windowing {
		class Window {
		public:
			virtual ~Window() = default;

			static std::unique_ptr<Window> Create(const WindowProps & = WindowProps());
		};
	}
}