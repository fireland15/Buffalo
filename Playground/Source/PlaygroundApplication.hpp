#pragma once

#include <iostream>
#include <Buffalo/Core/Application.hpp>

class PlaygroundApplication : public Buffalo::Application {
public:
	PlaygroundApplication();

	~PlaygroundApplication();

	virtual void OnUpdate() override;
};