#pragma once

#include <memory>
#include <Buffalo/Core/Application.hpp>
#include <Buffalo/Events/EventBus.hpp>
#include <Buffalo/Core.hpp>

namespace Buffalo {
	class ApplicationBuilder {
	public:
		template<typename TApplication>
		Unique<TApplication> Build() {
			return std::make_unique<TApplication>(std::move(eventBus));
		}
	};
}