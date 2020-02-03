#include <Meatball/Rendering/Model.hpp>
#include <Meatball/Rendering/Material.hpp>
#include <Meatball/Rendering/Mesh.hpp>
#include <glm/gtx/transform.hpp>
#include <Meatball/Core/Debug.hpp>

namespace Meatball {
	namespace Rendering {
		Model::Model(Material& material, Mesh& mesh)
			: material(material)
			, mesh(mesh)
			, translation(glm::vec3(0.f))
			, modelMatrix(InitializeModelMatrix()) {
			MEATBALL_PROFILE_FUNC();
		}

		Model::~Model() = default;

		void Model::RecalculateModelMatrix() {
			MEATBALL_PROFILE_FUNC();
			modelMatrix = InitializeModelMatrix();
		}

		glm::mat4 Model::InitializeModelMatrix() {
			MEATBALL_PROFILE_FUNC();
			return glm::translate(translation);
		}

		const glm::vec3& Model::GetTranslation() {
			MEATBALL_PROFILE_FUNC();
			return translation;
		}

		void Model::SetTranslation(const glm::vec3& t) {
			MEATBALL_PROFILE_FUNC();
			translation = t;
			RecalculateModelMatrix();
		}
	}
}