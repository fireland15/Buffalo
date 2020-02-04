#pragma once

#include <Buffalo/Windowing/Window.hpp>

namespace Buffalo {
    namespace Windowing {
        static std::unique_ptr<Window> Create(const WindowProps & = WindowProps());
    }
}