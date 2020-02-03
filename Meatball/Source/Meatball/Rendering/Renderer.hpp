#pragma once

#include <glm/glm.hpp>
#include <stack>

namespace Meatball {
    namespace Rendering {
		class Camera;
		class Material;
		class Mesh;

		class Renderer {
		public:
			Renderer();

			virtual ~Renderer() = default;

			virtual void BeginScene(const Camera& camera);

			virtual void Draw(Mesh& mesh, Material& material, const glm::mat4 modelMatrix);

			virtual void EndScene();

			virtual void ClearBuffers();

		private:
			void PushMatrix(const glm::mat4& matrix);

			void PopMatrix();

			void ClearMatrixStack();

			const glm::mat4& CurrentMatrix();

		private:
			std::stack<glm::mat4> matrixStack;
		};
    }
}