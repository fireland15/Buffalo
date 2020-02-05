#include <Buffalo/Core/TypeDefs.hpp>
#include <Buffalo/Events/EventBus.hpp>
#include <functional>

#define BUFFALO_BIND_EVENT_HANDLER(func) std::bind(&func, this, std::placeholders::_1)