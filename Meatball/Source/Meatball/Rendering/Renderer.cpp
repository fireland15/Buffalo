#include <Meatball/Rendering/Renderer.hpp>
#include <Meatball/Rendering/Camera.hpp>
#include <Meatball/Rendering/Material.hpp>
#include <Meatball/Rendering/Mesh.hpp>
#include <Meatball/Rendering/GL.hpp>
#include <Meatball/Rendering/Program.hpp>
#include <Meatball/Core/Debug.hpp>

static std::string MVP_MATRIX_UNIFORM_NAME("u_mvp");

namespace Meatball {
	namespace Rendering {
		Renderer::Renderer() 
			: matrixStack({ glm::mat4(1.f) }) {
			MEATBALL_PROFILE_FUNC();
		}

		void Renderer::BeginScene(const Camera& camera) {
			MEATBALL_PROFILE_FUNC();
			ClearMatrixStack();
			PushMatrix(camera.GetViewProjectionMatrix());
		}

		void Renderer::Draw(Mesh& mesh, Material& material, const glm::mat4 modelMatrix) {
			MEATBALL_PROFILE_FUNC();
			PushMatrix(modelMatrix);
			const auto& currentMatrix = CurrentMatrix();

			material.PreDraw();
			auto& mvpUniform = material.Program.GetUniform(MVP_MATRIX_UNIFORM_NAME);
			material.Program.SetUniform(mvpUniform, currentMatrix);
			mesh.PreDraw();
			GL::DrawArrays(PrimitiveDrawMode::Triangles, 0, static_cast<GLsizei>(mesh.VertexCount));
			mesh.PostDraw();
			material.PostDraw();

			PopMatrix();
		}

		void Renderer::EndScene() {
			MEATBALL_PROFILE_FUNC();
		}

		void Renderer::ClearBuffers() {
			MEATBALL_PROFILE_FUNC();
			GL::Clear(GL_COLOR_BUFFER_BIT);
		}

		void Renderer::PushMatrix(const glm::mat4& matrix) {
			MEATBALL_PROFILE_FUNC();
			const auto& top = matrixStack.top();
			matrixStack.push(top * matrix);
		}

		void Renderer::PopMatrix() {
			MEATBALL_PROFILE_FUNC();
			matrixStack.pop();
		}

		void Renderer::ClearMatrixStack() {
			MEATBALL_PROFILE_FUNC();
			std::stack<glm::mat4> freshMatrixStack({ glm::mat4(1.f) });
			matrixStack.swap(freshMatrixStack);
		}

		const glm::mat4& Renderer::CurrentMatrix() {
			MEATBALL_PROFILE_FUNC();
			return matrixStack.top();
		}
	}
}