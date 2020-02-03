#pragma once

#include <glm/glm.hpp>

namespace Meatball {
	namespace Rendering {
		class Material;
		class Mesh;

		class Model {
		public:
			Model(Material& material, Mesh& mesh);

			Model(const Model&) = delete;
			
			Model(Model&&) = delete;

			Model& operator=(const Model&) = delete;

			Model& operator=(Model&&) = delete;

			virtual ~Model();

			const glm::vec3& GetTranslation();

			void SetTranslation(const glm::vec3& translation);

			inline const glm::mat4& GetModelMatrix() { return modelMatrix; }

			inline Material& GetMaterial() { return material; }

			inline Mesh& GetMesh() { return mesh; }

		private:
			void RecalculateModelMatrix();

			glm::mat4 InitializeModelMatrix();

		private:
			glm::vec3 translation;

			glm::mat4 modelMatrix;

			Material& material;

			Mesh& mesh;
		};
	}
}