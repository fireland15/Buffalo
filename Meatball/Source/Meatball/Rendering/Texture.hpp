#pragma once

#include <Meatball/Rendering/TextureTarget.hpp>
#include <Meatball/Rendering/TextureInternalFormat.hpp>
#include <Meatball/Rendering/PixelFormat.hpp>
#include <Meatball/Rendering/PixelDataType.hpp>
#include <Meatball/Rendering/FilterType.hpp>

namespace Meatball {
	namespace Rendering {
		class Texture {
		public:
			Texture();
			Texture(const Texture&) = delete;
			Texture(Texture&&) = delete;
			Texture& operator=(const Texture&) = delete;
			Texture& operator=(Texture&&) = delete;
			~Texture();

			void Bind(TextureTarget target);
			void SetData(TextureInternalFormat internalFormat, PixelFormat format, PixelDataType type, GLsizei width, GLsizei height, const GLvoid* data);
			void SetMagFilter(FilterType filter);
			void SetMinFilter(FilterType filter);
			void SetWrapS();
			void SetWrapT();
			void Unbind();

		private:
			GLuint handle;
			TextureTarget target = TextureTarget::NoTarget;
		};
	}
}