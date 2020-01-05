#include <Meatball/Windowing/ScriptedTestWindow.hpp>
#include <Meatball/Events/EventBus.hpp>
#include <Meatball/Events/EventType.hpp>
#include <Meatball/Events/EventDispatcher.hpp>
#include <Meatball/Core.hpp>
#include <Meatball/Core/Debug.hpp>

namespace Meatball {
	namespace Windowing {
		ScriptedTestWindow::ScriptedTestWindow(Unique<Events::EventDispatcher> eventDispatcher)
			: _eventDispatcher(std::move(eventDispatcher)) {
			_eventDispatcher->
				AddEventHandler(Events::EventType::ApplicationShutdown, MEATBALL_BIND_EVENT_HANDLER(ScriptedTestWindow::OnApplicationShutdown));
		}

		void ScriptedTestWindow::OnUpdate() {
			MEATBALL_PROFILE_FUNC();
			_eventDispatcher->DispatchEvents();
		}

		void ScriptedTestWindow::OnApplicationShutdown(Shared<Events::Event> event) {
			MEATBALL_PROFILE_FUNC();
			MEATBALL_LOG_DEBUG("Closing window for application shutdown.");
		}
	}
}