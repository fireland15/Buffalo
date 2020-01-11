#pragma once

namespace Meatball {
	namespace Rendering {
		class GraphicsContext {
		public:

			virtual void Init() = 0;

			virtual void SwapBuffers() = 0;

		};
	}
}