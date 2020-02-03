#include <Meatball/Rendering/Renderer.hpp>
#include <Meatball/Rendering/Camera.hpp>
#include <Meatball/Rendering/Material.hpp>
#include <Meatball/Rendering/Mesh.hpp>
#include <Meatball/Rendering/GL.hpp>
#include <Meatball/Rendering/Program.hpp>

static std::string MVP_MATRIX_UNIFORM_NAME("u_mvp");

namespace Meatball {
	namespace Rendering {
		Renderer::Renderer() 
			: matrixStack({ glm::mat4(1.f) }) { }

		void Renderer::BeginScene(const Camera& camera) {
			ClearMatrixStack();
			PushMatrix(camera.ViewProjectionMatrix());
		}

		void Renderer::Draw(Mesh& mesh, Material& material, const glm::mat4 modelMatrix) {
			PushMatrix(modelMatrix);
			const auto& currentMatrix = CurrentMatrix();

			material.PreDraw();
			auto& mvpUniform = material.Program.GetUniform(MVP_MATRIX_UNIFORM_NAME);
			material.Program.SetUniform(mvpUniform, currentMatrix);
			mesh.PreDraw();
			GL::DrawArrays(PrimitiveDrawMode::Triangles, 0, mesh.VertexCount);
			mesh.PostDraw();
			material.PostDraw();

			PopMatrix();
		}

		void Renderer::EndScene() {

		}

		void Renderer::ClearBuffers() {
			GL::Clear(GL_COLOR_BUFFER_BIT);
		}

		void Renderer::PushMatrix(const glm::mat4& matrix) {
			const auto& top = matrixStack.top();
			matrixStack.push(top * matrix);
		}

		void Renderer::PopMatrix() {
			matrixStack.pop();
		}

		void Renderer::ClearMatrixStack() {
			matrixStack.swap(std::stack<glm::mat4>({ glm::mat4(1.f) }));
		}

		const glm::mat4& Renderer::CurrentMatrix() {
			return matrixStack.top();
		}
	}
}