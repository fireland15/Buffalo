#pragma once

#include <glm/glm.hpp>

namespace Meatball {
    namespace Rendering {
		class OrthographicCamera;
		class Shader;
		class VertexArray;

		class Renderer {
		public:
			virtual ~Renderer() = default;

			virtual void BeginScene(const OrthographicCamera& camera) = 0;

			virtual void DrawVertices(VertexArray* vertexArray, Shader* shader, const glm::mat4& modelMatrix) = 0;

			virtual void EndScene() = 0;
			
		protected:
			static Renderer* s_renderer;
		};
    }
}