#include <Meatball/Windowing/ScriptedTestWindow.hpp>

#include <Meatball/Events/EventBus.hpp>
#include <Meatball/Events/EventType.hpp>

namespace Meatball {
	namespace Windowing {
		void ScriptedTestWindow::AttachEventBus(Events::EventBus& eventBus) {
			eventBus.AddEventReceiver(&eventReceiver, Events::EventType::ApplicationTick);
		}
	}
}