#include <PlaygroundApplication.hpp>

#include <iostream>

PlaygroundApplication::PlaygroundApplication()
		: Application() {

}

PlaygroundApplication::~PlaygroundApplication() {
}

Meatball::Unique<Meatball::Application> Meatball::CreateApplication() {
	return std::make_unique<PlaygroundApplication>();
}