#pragma once

#include <memory>

namespace Meatball {
	template<typename T>
	using Unique = std::unique_ptr<T>;

	template<typename T>
	using Shared = std::shared_ptr<T>;
}