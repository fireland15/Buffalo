#include <Buffalo/Rendering/Renderer.hpp>
#include <Buffalo/Rendering/Camera.hpp>
#include <Buffalo/Rendering/Material.hpp>
#include <Buffalo/Rendering/Mesh.hpp>
#include <Buffalo/Rendering/GL.hpp>
#include <Buffalo/Rendering/Program.hpp>
#include <Buffalo/Core/Debug.hpp>

static std::string MVP_MATRIX_UNIFORM_NAME("u_mvp");

namespace Buffalo {
	namespace Rendering {
		Renderer::Renderer() 
			: matrixStack({ glm::mat4(1.f) }) {
			BUFFALO_PROFILE_FUNC();
			GL::Enable(Buffalo::Rendering::Capability::DepthTest);
		}

		void Renderer::BeginScene(const Camera& camera) {
			BUFFALO_PROFILE_FUNC();
			ClearMatrixStack();
			PushMatrix(camera.GetViewProjectionMatrix());
		}

		void Renderer::Draw(Mesh& mesh, Material& material, const glm::mat4 modelMatrix) {
			BUFFALO_PROFILE_FUNC();
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
			BUFFALO_PROFILE_FUNC();
		}

		void Renderer::ClearBuffers() {
			BUFFALO_PROFILE_FUNC();
			GL::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Renderer::PushMatrix(const glm::mat4& matrix) {
			BUFFALO_PROFILE_FUNC();
			const auto& top = matrixStack.top();
			matrixStack.push(top * matrix);
		}

		void Renderer::PopMatrix() {
			BUFFALO_PROFILE_FUNC();
			matrixStack.pop();
		}

		void Renderer::ClearMatrixStack() {
			BUFFALO_PROFILE_FUNC();
			std::stack<glm::mat4> freshMatrixStack({ glm::mat4(1.f) });
			matrixStack.swap(freshMatrixStack);
		}

		const glm::mat4& Renderer::CurrentMatrix() {
			BUFFALO_PROFILE_FUNC();
			return matrixStack.top();
		}
	}
}