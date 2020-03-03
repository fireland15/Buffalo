#pragma once

#include <Buffalo/Core/Typedefs.hpp>

namespace Buffalo {
	namespace Rendering {
		class Mesh;

		class MeshFactory {
		public:
			Buffalo::Unique<Mesh> MakeCube();

			Buffalo::Unique<Mesh> MakeCapsule(float length, float radius, int resolutionFactor = 4);

			Buffalo::Unique<Mesh> MakeCylinder(float length, float radius);
		};
	}
}