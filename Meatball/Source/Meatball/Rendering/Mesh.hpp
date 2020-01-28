#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <Meatball/Core.hpp>

namespace Meatball {
	namespace Rendering {
		class VertexArray;
		class Buffer;

		class Mesh {
		public:
			Mesh(const std::vector<glm::vec3>& vertices);
			
			Mesh(const Mesh&) = delete;
			
			Mesh(Mesh&&) = delete;
			
			Mesh& operator=(const Mesh&) = delete;
			
			Mesh& operator=(Mesh&&) = delete;

			~Mesh();

			void PreDraw();

			void PostDraw();

		public:
			const std::size_t VertexCount;

		private:
			Unique<VertexArray> vertexArray;

			Unique<Buffer> vertexBuffer;

			const static unsigned int VERTEX_ATTRIB_LOCATION;
		};
	}
}