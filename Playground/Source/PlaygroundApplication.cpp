#include <PlaygroundApplication.hpp>

#include <iostream>

PlaygroundApplication::PlaygroundApplication() {
}

Meatball::Application* Meatball::CreateApplication() {
	return new PlaygroundApplication();
}