#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <Meatball/Core.hpp>
#include <glad/glad.h>

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

			~Mesh() = default;

			void PreDraw();

			void PostDraw();

		public:
			const std::size_t VertexCount;

		private:
			Unique<VertexArray> vertexArray;

			Unique<Buffer> vertexBuffer;

			const static GLuint VERTEX_ATTRIB_LOCATION;
		};
	}
}