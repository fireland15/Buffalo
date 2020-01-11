#include <iostream>
#include <Meatball/Core/Application.hpp>
#include <Meatball/Core/Debug.hpp>

extern Meatball::Unique<Meatball::Application> Meatball::CreateApplication();

int main() {
    std::ios::sync_with_stdio(false);
	
	MEATBALL_INIT_LOG();
	MEATBALL_PROFILE_INIT();

    auto app = Meatball::CreateApplication();
    app->Run();
}