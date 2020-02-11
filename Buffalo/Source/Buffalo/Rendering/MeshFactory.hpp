#pragma once

#include <Buffalo/Core/Typedefs.hpp>

namespace Buffalo {
	namespace Rendering {
		class Mesh;

		class MeshFactory {
		public:
			Buffalo::Unique<Mesh> MakeCube();
		};
	}
}