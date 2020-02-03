#include <PlaygroundApplication.hpp>

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <Meatball/Rendering/Material.hpp>
#include <Meatball/Rendering/Mesh.hpp>
#include <Meatball/Rendering/Program.hpp>
#include <Meatball/Rendering/Shader.hpp>
#include <Meatball/Rendering/Material.hpp>
#include <Meatball/Rendering/Renderer.hpp>
#include <Meatball/Rendering/Camera.hpp>
#include <Meatball/Core.hpp>
#include <Meatball/Core/Debug.hpp>
#include <Meatball/Rendering/Model.hpp>

static Meatball::Unique<Meatball::Rendering::Mesh> mesh;
static Meatball::Unique<Meatball::Rendering::Material> material;
static Meatball::Unique<Meatball::Rendering::Program> program;
static Meatball::Unique<Meatball::Rendering::Model> model;
static Meatball::Unique<Meatball::Rendering::Renderer> renderer;
static Meatball::Rendering::Camera camera(glm::mat4(1.f));

std::string vertexSource = R"x(
#version 410
layout(location = 0) in vec3 a_position;
uniform vec4 u_color;
uniform mat4 u_mvp;
out vec4 v_color;
void main() {
	gl_Position = u_mvp * vec4(a_position, 1.0);
	v_color = u_color;
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

PlaygroundApplication::PlaygroundApplication()
		: Application() {
	renderer = std::make_unique<Meatball::Rendering::Renderer>();
	std::vector<glm::vec3> vertices;
	vertices.emplace_back(0.f, 0.f, 0.f);
	vertices.emplace_back(0.f, 1.f, 0.f);
	vertices.emplace_back(1.f, 1.f, 0.f);

	mesh = std::make_unique<Meatball::Rendering::Mesh>(vertices);

	Meatball::Rendering::Shader vertexShader(Meatball::Rendering::ShaderType::Vertex);
	vertexShader.AddSource(vertexSource);
	vertexShader.Compile();

	Meatball::Rendering::Shader fragmentShader(Meatball::Rendering::ShaderType::Fragment);
	fragmentShader.AddSource(fragmentSource);
	fragmentShader.Compile();

	program = std::make_unique<Meatball::Rendering::Program>();
	program->AttachShader(vertexShader);
	program->AttachShader(fragmentShader);
	program->Link();
	program->DetachShader(vertexShader);
	program->DetachShader(fragmentShader);
	vertexShader.~Shader();
	fragmentShader.~Shader();

	material = std::make_unique<Meatball::Rendering::Material>(glm::vec4(1.f, 0.5f, 0.75f, 1.f), *program);

	model = std::make_unique<Meatball::Rendering::Model>(*material, *mesh);
}

PlaygroundApplication::~PlaygroundApplication() {
	mesh.release();
	material.release();
	program.release();
}

void PlaygroundApplication::OnUpdate() {
	auto translation = model->GetTranslation();
	translation.x -= 0.0001f;
	model->SetTranslation(translation);

	renderer->ClearBuffers();
	renderer->BeginScene(camera);
	renderer->Draw(model->GetMesh(), model->GetMaterial(), model->GetModelMatrix());
	renderer->EndScene();

}

Meatball::Unique<Meatball::Application> Meatball::CreateApplication() {
	return std::make_unique<PlaygroundApplication>();
}