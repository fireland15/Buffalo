#pragma once

#include <Meatball/Windowing/Window.hpp>

namespace Meatball {
    namespace Windowing {
        static std::unique_ptr<Window> Create(const WindowProps & = WindowProps());
    }
}