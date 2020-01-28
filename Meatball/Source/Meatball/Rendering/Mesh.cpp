#include <Meatball/Rendering/Mesh.hpp>

#include <Meatball/Rendering/VertexArray.hpp>
#include <Meatball/Rendering/Buffer.hpp>
#include <Meatball/Rendering/AttributeBufferDataPointer.hpp>
#include <Meatball/Core/Debug.hpp>

namespace Meatball {
	namespace Rendering {
		const GLuint Mesh::VERTEX_ATTRIB_LOCATION = 0U;

		Mesh::Mesh(const std::vector<glm::vec3>& vertices) 
			: VertexCount(vertices.size()) {
			MEATBALL_PROFILE_FUNC();
			vertexBuffer = std::make_unique<Buffer>();
			vertexBuffer->Bind(BufferTarget::ArrayBuffer);
			vertexBuffer->Reserve(vertices.size() * sizeof(glm::vec3), BufferUsage::StaticDraw);
			vertexBuffer->SetData(vertices.data(), vertices.size() * sizeof(glm::vec3));

			AttributeBufferDataPointer ptr(*vertexBuffer, 3, AttributeDataType::Float, 0, 0);

			vertexArray = std::make_unique<VertexArray>();
			vertexArray->Bind();
			vertexArray->SetAttributePointer(VERTEX_ATTRIB_LOCATION, ptr);
			vertexArray->EnableAttribute(VERTEX_ATTRIB_LOCATION);
			vertexBuffer->Unbind();
			vertexArray->Unbind();
		}

		Mesh::~Mesh() = default;

		void Mesh::PreDraw() {
			MEATBALL_PROFILE_FUNC();
			vertexArray->Bind();
		}

		void Mesh::PostDraw() {
			MEATBALL_PROFILE_FUNC();
			vertexArray->Unbind();
		}
	}
}