#include <Meatball/Core/TypeDefs.hpp>

#include <functional>

#define MEATBALL_BIND_EVENT_HANDLER(func) std::bind(&func, this, std::placeholders::_1)