#include <Buffalo/Rendering/MeshFactory.hpp>
#include <Buffalo/Rendering/Mesh.hpp>
#include <glm/glm.hpp>
#include <vector>

namespace Buffalo {
	namespace Rendering {
		Buffalo::Unique<Mesh> MeshFactory::MakeCube() {
			const glm::vec3 verts[8] = {
				{ 0.5f, -0.5f, -0.5f },
				{ 0.5f, -0.5f, 0.5f },
				{ -0.5f, -0.5f, -0.5f },
				{ -0.5f, -0.5f, 0.5f },
				{ 0.5f, 0.5f, 0.5f },
				{ 0.5f, 0.5f, -0.5f },
				{ -0.5f, 0.5f, 0.5f },
				{ -0.5f, 0.5f, -0.5f }
			};

			const int indices[36] = {
				// bottom
				2, 0, 3,
				0, 1, 3,

				//top
				6, 4, 7,
				4, 5, 7,

				// front
				7, 5, 2,
				5, 0, 2,
				   	
				// back
				4, 6, 1,
				6, 3, 1,
				   	  
				// left
				6, 7, 3,
				7, 2, 3,
				   	  
				// right
				4, 5, 1,
				5, 0, 1
			};

			std::vector<glm::vec3> actualVerts(36);

			for (int i = 0; i < 36; i++) {
				actualVerts[i] = verts[indices[i]];
			}

			return std::make_unique<Mesh>(actualVerts);
		}
	}
}