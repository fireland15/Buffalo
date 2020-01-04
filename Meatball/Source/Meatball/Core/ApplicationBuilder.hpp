#pragma once

#include <memory>
#include <Meatball/Core/Application.hpp>

namespace Meatball {
	class ApplicationBuilder {
	public:
		std::unique_ptr<Application> Build();
	};
}