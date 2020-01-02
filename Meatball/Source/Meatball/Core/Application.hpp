#pragma once

namespace Meatball {
	class Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

    Application* CreateApplication();
}