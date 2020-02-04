#include <iostream>
#include <Buffalo/Core/Application.hpp>
#include <Buffalo/Core/Debug.hpp>

extern Buffalo::Unique<Buffalo::Application> Buffalo::CreateApplication();

int main() {
    std::ios::sync_with_stdio(false);
	
	BUFFALO_INIT_LOG();
	BUFFALO_PROFILE_INIT();

    auto app = Buffalo::CreateApplication();
    app->Run();
}