#include <Buffalo/Rendering/Mesh.hpp>

#include <Buffalo/Rendering/VertexArray.hpp>
#include <Buffalo/Rendering/Buffer.hpp>
#include <Buffalo/Rendering/AttributeBufferDataPointer.hpp>
#include <Buffalo/Core/Debug.hpp>

namespace Buffalo {
	namespace Rendering {
		const GLuint Mesh::VERTEX_ATTRIB_LOCATION = 0U;

		Mesh::Mesh(const std::vector<glm::vec3>& vertices) 
			: VertexCount(vertices.size()) {
			BUFFALO_PROFILE_FUNC();
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
			BUFFALO_PROFILE_FUNC();
			vertexArray->Bind();
		}

		void Mesh::PostDraw() {
			BUFFALO_PROFILE_FUNC();
			vertexArray->Unbind();
		}
	}
}