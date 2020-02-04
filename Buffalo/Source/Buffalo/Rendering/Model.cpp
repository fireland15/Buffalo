#include <Buffalo/Rendering/Model.hpp>
#include <Buffalo/Rendering/Material.hpp>
#include <Buffalo/Rendering/Mesh.hpp>
#include <glm/gtx/transform.hpp>
#include <Buffalo/Core/Debug.hpp>

namespace Buffalo {
	namespace Rendering {
		Model::Model(Material& material, Mesh& mesh)
			: material(material)
			, mesh(mesh)
			, translation(glm::vec3(0.f))
			, modelMatrix(InitializeModelMatrix()) {
			BUFFALO_PROFILE_FUNC();
		}

		Model::~Model() = default;

		void Model::RecalculateModelMatrix() {
			BUFFALO_PROFILE_FUNC();
			modelMatrix = InitializeModelMatrix();
		}

		glm::mat4 Model::InitializeModelMatrix() {
			BUFFALO_PROFILE_FUNC();
			return glm::translate(translation);
		}

		const glm::vec3& Model::GetTranslation() {
			BUFFALO_PROFILE_FUNC();
			return translation;
		}

		void Model::SetTranslation(const glm::vec3& t) {
			BUFFALO_PROFILE_FUNC();
			translation = t;
			RecalculateModelMatrix();
		}
	}
}