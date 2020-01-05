#pragma once

#include <Meatball/Core.hpp>
#include <Meatball/Windowing/Window.hpp>
#include <Meatball/Events/EventReceiver.hpp>

namespace Meatball {
	namespace Events {
		class EventDispatcher;
	}

	namespace Windowing {		
		class ScriptedTestWindow : public Window {
		public:
			ScriptedTestWindow(Unique<Events::EventDispatcher> eventDispatcher);

			virtual ~ScriptedTestWindow() = default;

			virtual void OnUpdate();

			void OnApplicationShutdown(Shared<Events::Event> event);

		private:
			Unique<Events::EventDispatcher> _eventDispatcher;
		};
	}
}