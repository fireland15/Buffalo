#pragma once

#include <memory>
#include <Meatball/Core/Application.hpp>
#include <Meatball/Events/EventBus.hpp>
#include <Meatball/Core.hpp>

namespace Meatball {
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