#include <Meatball/Windowing/ScriptedTestWindow.hpp>
#include <Meatball/Events/EventBus.hpp>
#include <Meatball/Events/EventType.hpp>
#include <Meatball/Events/EventDispatcher.hpp>
#include <Meatball/Events/ApplicationEvent.hpp>
#include <Meatball/Core.hpp>
#include <Meatball/Core/Debug.hpp>

#include <time.h>
#include <stdlib.h>>

namespace Meatball {
	namespace Windowing {
		ScriptedTestWindow::ScriptedTestWindow(Unique<Events::EventDispatcher> eventDispatcher)
			: Window(std::move(eventDispatcher)) {
			GetEventDispatcher()
				.AddEventHandler(Events::EventType::ApplicationShutdown, MEATBALL_BIND_EVENT_HANDLER(ScriptedTestWindow::OnApplicationShutdown));

			srand(time(NULL));
		}

		void ScriptedTestWindow::OnUpdate() {
			MEATBALL_PROFILE_FUNC();
			GetEventDispatcher().DispatchEvents();

			if (rand() % 10 == 7) {
				GetEventBus().Publish<Events::ApplicationTickEvent>();
			}
		}

		void ScriptedTestWindow::OnApplicationShutdown(Shared<Events::Event> event) {
			MEATBALL_PROFILE_FUNC();
			MEATBALL_LOG_DEBUG("Closing window for application shutdown.");
		}
	}
}