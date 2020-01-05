#pragma once

#include <Meatball/Windowing/Window.hpp>
#include <Meatball/Events/EventReceiver.hpp>

namespace Meatball {
	namespace Windowing {
		class ScriptedTestWindow : public Window {
		public:
			virtual ~ScriptedTestWindow() = default;

			virtual void AttachEventBus(Events::EventBus& eventBus);

		private:
			Events::EventReceiver eventReceiver;
		};
	}
}