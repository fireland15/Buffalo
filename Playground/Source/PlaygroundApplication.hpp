#pragma once

#include <iostream>
#include <Meatball/Core/Application.hpp>

class PlaygroundApplication : public Meatball::Application {
public:
	PlaygroundApplication();

	~PlaygroundApplication();

	virtual void OnUpdate() override;
};