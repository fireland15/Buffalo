#include <iostream>
#include <Meatball/Core/Application.hpp>
#include <Meatball/Core/Debug.hpp>
#include <Meatball/Core/Debug/Logging/FileLogger.hpp>

extern Meatball::Unique<Meatball::Application> Meatball::CreateApplication();

int main() {
    std::ios::sync_with_stdio(false);
	
	MEATBALL_INIT_LOG(std::make_unique<Meatball::Logging::FileLogger>("log"));

    auto app = Meatball::CreateApplication();
    app->Run();
}