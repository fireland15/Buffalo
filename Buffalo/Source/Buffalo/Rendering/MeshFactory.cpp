#include <Buffalo/Rendering/MeshFactory.hpp>
#include <Buffalo/Rendering/Mesh.hpp>
#include <glm/glm.hpp>
#include <vector>
#include <cmath>

const float PI = 3.1415927f;
const float TAO = 6.2831854f;

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

		Buffalo::Unique<Mesh> MeshFactory::MakeCapsule(float length, float radius) {
			const std::size_t radialDivisions = 16L;
			float radialSegmentLength = (radius * PI) / 8.f;
			std::size_t verticalDivisions = static_cast<std::size_t>(std::ceilf(length / radialSegmentLength));
			float verticalSegmentLength = length / verticalDivisions;

			/// Just the cylinder right now...
			std::size_t vertexCount = radialDivisions * (verticalDivisions + 1L);

			std::vector<glm::vec3> vertices(vertexCount);

			const float angularStep = TAO / radialDivisions;


			// Cylinder
			for (std::size_t v = 0; v < verticalDivisions + 1L; v++) {
				for (std::size_t r = 0; r < radialDivisions; r++) {
					glm::vec3& vert = vertices[v * radialDivisions + r];
					float angle = r * angularStep;
					vert.x = radius * std::sinf(angle);
					vert.y = v * verticalSegmentLength + radius;
					vert.z = radius * std::cosf(angle);
				}
			}

			std::vector<std::size_t> indices;

			/*
			i2-----i3
			|	  /	|
			|	/	|
			| /		|
			i0-----i1
			*/

			for (std::size_t v = 0; v < verticalDivisions; v++) {
				for (std::size_t r = 0; r < radialDivisions; r++) {
					auto i0 = r + (v * radialDivisions);
					auto i1 = (i0 + 1) % radialDivisions == 0 ? i0 + 1 - radialDivisions : i0 + 1;
					auto i2 = r + ((v + 1) * radialDivisions);
					auto i3 = (i2 + 1) % radialDivisions == 0 ? i2 + 1 - radialDivisions : i2 + 1;

					indices.push_back(i0);
					indices.push_back(i1);
					indices.push_back(i3);
					indices.push_back(i0);
					indices.push_back(i3);
					indices.push_back(i2);
				}
			}

			std::vector<glm::vec3> actualVerts(indices.size());
			for (int i = 0; i < indices.size(); i++) {
				actualVerts[i] = vertices[indices[i]];
			}
			return std::make_unique<Mesh>(actualVerts);
		}

		Buffalo::Unique<Mesh> MeshFactory::MakeCylinder(float length, float radius) {
			const std::size_t radialDivisions = 16L;
			float radialSegmentLength = (radius * PI) / 8.f;
			std::size_t verticalDivisions = static_cast<std::size_t>(std::ceilf(length / radialSegmentLength));
			float verticalSegmentLength = length / verticalDivisions;

			std::size_t vertexCount = radialDivisions * (verticalDivisions + 1L) + 2;

			std::vector<glm::vec3> vertices(vertexCount);

			const float angularStep = TAO / radialDivisions;


			// Bottom Center
			vertices[0].x = 0;
			vertices[0].y = 0;
			vertices[0].z = 0;

			// Cylinder Walls
			for (std::size_t v = 0; v < verticalDivisions + 1L; v++) {
				for (std::size_t r = 0; r < radialDivisions; r++) {
					glm::vec3& vert = vertices[v * radialDivisions + r + 1];
					float angle = r * angularStep;
					vert.x = radius * std::sinf(angle);
					vert.y = v * verticalSegmentLength;
					vert.z = radius * std::cosf(angle);
				}
			}

			// Top Center
			vertices[vertices.size() - 1].x = 0;
			vertices[vertices.size() - 1].y = length;
			vertices[vertices.size() - 1].z = 0;

			std::vector<std::size_t> indices;

			/*
			i2-----i3
			|	  /	|
			|	/	|
			| /		|
			i0-----i1
			*/
			
			// Bottom Cap
			for (std::size_t i = 0; i < radialDivisions; i++) {
				indices.push_back(0);
				indices.push_back(i + 1);
				indices.push_back((i + 1) % radialDivisions + 1);
			}

			for (std::size_t v = 0; v < verticalDivisions; v++) {
				for (std::size_t r = 0; r < radialDivisions; r++) {
					auto i0 = r + (v * radialDivisions);
					auto i1 = (i0 + 1) % radialDivisions == 0 ? i0 + 1 - radialDivisions : i0 + 1;
					auto i2 = r + ((v + 1) * radialDivisions);
					auto i3 = (i2 + 1) % radialDivisions == 0 ? i2 + 1 - radialDivisions : i2 + 1;

					indices.push_back(i0 + 1);
					indices.push_back(i1 + 1);
					indices.push_back(i3 + 1);
					indices.push_back(i0 + 1);
					indices.push_back(i3 + 1);
					indices.push_back(i2 + 1);
				}
			}

			// Top Cap
			std::size_t lastRingIndex = verticalDivisions * radialDivisions;
			for (std::size_t i = 0; i < radialDivisions; i++) {
				indices.push_back(vertices.size() - 1);
				indices.push_back(lastRingIndex + i + 1);
				indices.push_back(lastRingIndex + ((i + 1) % radialDivisions) + 1);
			}

			std::vector<glm::vec3> actualVerts(indices.size());
			for (int i = 0; i < indices.size(); i++) {
				actualVerts[i] = vertices[indices[i]];
			}
			return std::make_unique<Mesh>(actualVerts);
		}

	}
}