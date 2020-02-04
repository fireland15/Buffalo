#pragma once

#include <memory>
#include <Buffalo/Core/Application.hpp>
#include <Buffalo/Events/EventBus.hpp>
#include <Buffalo/Core.hpp>

namespace Buffalo {
	class ApplicationBuilder {
	public:
		template<typename TEventBus, typename ...TEventBusCtorArgs>
		ApplicationBuilder& AddEventBus(TEventBusCtorArgs... args) {
			eventBus = std::make_unique<TEventBus>(args...);

			return *this;
		}

		template<typename TApplication>
		Unique<TApplication> Build() {
			return std::make_unique<TApplication>(std::move(eventBus));
		}

	private:
		Unique<Events::EventBus> eventBus;
	};
}