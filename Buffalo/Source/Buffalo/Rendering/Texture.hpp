#pragma once

#include <Buffalo/Rendering/TextureTarget.hpp>
#include <Buffalo/Rendering/TextureInternalFormat.hpp>
#include <Buffalo/Rendering/PixelFormat.hpp>
#include <Buffalo/Rendering/PixelDataType.hpp>
#include <Buffalo/Rendering/FilterType.hpp>

namespace Buffalo {
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