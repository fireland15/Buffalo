#include <Buffalo/Core/TypeDefs.hpp>
#include <Buffalo/Events/EventBus.hpp>
#include <Buffalo/Core/InputState.hpp>
#include <functional>

#define BUFFALO_BIND_EVENT_HANDLER(func) std::bind(&func, this, std::placeholders::_1)

#define BUFFALO_ADD_EVENT_HANDLER(dispatcher, eventType, func) dispatcher->AddEventHandler(eventType, BUFFALO_BIND_EVENT_HANDLER(func));