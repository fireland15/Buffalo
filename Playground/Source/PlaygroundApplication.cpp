#include <PlaygroundApplication.hpp>

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <Buffalo/Rendering/Material.hpp>
#include <Buffalo/Rendering/Mesh.hpp>
#include <Buffalo/Rendering/Program.hpp>
#include <Buffalo/Rendering/Shader.hpp>
#include <Buffalo/Rendering/Material.hpp>
#include <Buffalo/Rendering/Renderer.hpp>
#include <Buffalo/Rendering/Camera.hpp>
#include <Buffalo/Rendering/OrthographicCamera.hpp>
#include <Buffalo/Core.hpp>
#include <Buffalo/Core/Debug.hpp>
#include <Buffalo/Rendering/Model.hpp>
#include <Buffalo/Events/EventDispatcher.hpp>

static Buffalo::Unique<Buffalo::Rendering::Mesh> mesh;
static Buffalo::Unique<Buffalo::Rendering::Material> material;
static Buffalo::Unique<Buffalo::Rendering::Program> program;
static Buffalo::Unique<Buffalo::Rendering::Model> model;
static Buffalo::Unique<Buffalo::Rendering::Renderer> renderer;
static Buffalo::Rendering::OrthographicCamera camera(1.f);

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
	renderer = std::make_unique<Buffalo::Rendering::Renderer>();
	std::vector<glm::vec3> vertices;
	vertices.emplace_back(0.f, 0.f, 0.f);
	vertices.emplace_back(0.f, 1.f, 0.f);
	vertices.emplace_back(1.f, 1.f, 0.f);

	mesh = std::make_unique<Buffalo::Rendering::Mesh>(vertices);

	Buffalo::Rendering::Shader vertexShader(Buffalo::Rendering::ShaderType::Vertex);
	vertexShader.AddSource(vertexSource);
	vertexShader.Compile();

	Buffalo::Rendering::Shader fragmentShader(Buffalo::Rendering::ShaderType::Fragment);
	fragmentShader.AddSource(fragmentSource);
	fragmentShader.Compile();

	program = std::make_unique<Buffalo::Rendering::Program>();
	program->AttachShader(vertexShader);
	program->AttachShader(fragmentShader);
	program->Link();
	program->DetachShader(vertexShader);
	program->DetachShader(fragmentShader);
	vertexShader.~Shader();
	fragmentShader.~Shader();

	material = std::make_unique<Buffalo::Rendering::Material>(glm::vec4(1.f, 0.5f, 0.75f, 1.f), *program);

	model = std::make_unique<Buffalo::Rendering::Model>(*material, *mesh);
}

PlaygroundApplication::~PlaygroundApplication() {
	mesh.release();
	material.release();
	program.release();
}

void PlaygroundApplication::OnUpdate() {
	renderer->ClearBuffers();
	renderer->BeginScene(camera);
	renderer->Draw(model->GetMesh(), model->GetMaterial(), model->GetModelMatrix());
	renderer->EndScene();

}

Buffalo::Unique<Buffalo::Application> Buffalo::CreateApplication() {
	return std::make_unique<PlaygroundApplication>();
}