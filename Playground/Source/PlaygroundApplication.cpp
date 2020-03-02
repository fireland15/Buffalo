#include <PlaygroundApplication.hpp>

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>
#include <Buffalo/Rendering/Material.hpp>
#include <Buffalo/Rendering/Mesh.hpp>
#include <Buffalo/Rendering/Program.hpp>
#include <Buffalo/Rendering/Shader.hpp>
#include <Buffalo/Rendering/Material.hpp>
#include <Buffalo/Rendering/Renderer.hpp>
#include <Buffalo/Rendering/Camera.hpp>
#include <Buffalo/Rendering/OrthographicCamera.hpp>
#include <Buffalo/Rendering/PerspectiveCamera.hpp>
#include <Buffalo/Core.hpp>
#include <Buffalo/Core/Debug.hpp>
#include <Buffalo/Rendering/Model.hpp>
#include <Buffalo/Rendering/CameraController.hpp>
#include <Buffalo/Events/EventDispatcher.hpp>
#include <Buffalo/Core/TimeStep.hpp>
#include <Buffalo/Rendering/MeshFactory.hpp>
#include <Buffalo/Rendering/ProgramFactory.hpp>

static Buffalo::Unique<Buffalo::Rendering::Mesh> mesh;
static Buffalo::Unique<Buffalo::Rendering::Material> material;
static Buffalo::Unique<Buffalo::Rendering::Program> program;
static Buffalo::Unique<Buffalo::Rendering::Model> model;
static Buffalo::Unique<Buffalo::Rendering::Renderer> renderer;
static Buffalo::Rendering::PerspectiveCamera camera(1.f);

std::string vertexSource = R"x(
#version 410
layout(location = 0) in vec3 a_position;
uniform vec4 u_color;
uniform mat4 u_mvp;
out vec4 v_color;
void main() {
	gl_Position = u_mvp * vec4(a_position, 1.0);
	v_color = u_color + vec4(a_position, 1.0);
}
)x";
std::string fragmentSource = R"x(
#version 410
in vec4 v_color;
out vec4 color;
void main() {
	color = v_color;
}
)x";

class PlaygroundCameraController : public Buffalo::Rendering::CameraController {
public:
	PlaygroundCameraController(Buffalo::Rendering::Camera& camera)
		: Buffalo::Rendering::CameraController(camera)
		, lookAt(0.f, 0.f, 0.f)
		, position(0.f) { 
	}

	virtual ~PlaygroundCameraController() = default;

	virtual void OnUpdate(const Buffalo::Core::TimeStep& timestep) override {
		const float step = 0.05f;
		if (Buffalo::InputState::IsKeyPressed(Buffalo::Key::A))
			position.x -= step;
		if (Buffalo::InputState::IsKeyPressed(Buffalo::Key::D))
			position.x += step;
		if (Buffalo::InputState::IsKeyPressed(Buffalo::Key::W))
			position.y -= step;
		if (Buffalo::InputState::IsKeyPressed(Buffalo::Key::S))
			position.y += step;
		if (Buffalo::InputState::IsKeyPressed(Buffalo::Key::Q))
			position.z -= step;
		if (Buffalo::InputState::IsKeyPressed(Buffalo::Key::Z))
			position.z += step;

		Buffalo::Rendering::Camera::UpdateMatricesUsingLookAt cameraUpdateParams(position, lookAt);
		camera.UpdateMatrices(cameraUpdateParams);
	}
	
private:
	glm::vec3 lookAt;
	glm::vec3 position;
};

static PlaygroundCameraController cameraController(camera);

PlaygroundApplication::PlaygroundApplication()
		: Application() {
	renderer = std::make_unique<Buffalo::Rendering::Renderer>();

	Buffalo::Rendering::MeshFactory meshFactory;
	mesh = meshFactory.MakeCapsule(4.f, 1.f);


	program = std::move(Buffalo::Rendering::ProgramFactory().CreateProgram(vertexSource, fragmentSource));

	material = std::make_unique<Buffalo::Rendering::Material>(glm::vec4(1.f, 0.5f, 0.75f, 1.f), *program);

	model = std::make_unique<Buffalo::Rendering::Model>(*material, *mesh);
}

PlaygroundApplication::~PlaygroundApplication() {
	mesh.release();
	material.release();
	program.release();
}

static float pos = 0.0f;

void PlaygroundApplication::OnUpdate() {
	Buffalo::Core::TimeStep ts;
	cameraController.OnUpdate(ts);

	renderer->ClearBuffers();
	renderer->BeginScene(camera);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	model->SetTranslation(glm::vec3(1.f, 0.f, 1.f));
	renderer->Draw(model->GetMesh(), model->GetMaterial(), model->GetModelMatrix());
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	model->SetTranslation(glm::vec3(-1.f, 0.f, -1.f));
	renderer->Draw(model->GetMesh(), model->GetMaterial(), model->GetModelMatrix());
	renderer->EndScene();

}

Buffalo::Unique<Buffalo::Application> Buffalo::CreateApplication() {
	return std::make_unique<PlaygroundApplication>();
}