#include <Buffalo/Rendering/Texture.hpp>
#include <Buffalo/Rendering/GL.hpp>
#include <Buffalo/Core/Debug.hpp>

namespace Buffalo {
	namespace Rendering {
		Texture::Texture() {
			BUFFALO_PROFILE_FUNC();
			GL::GenTextures(1, &handle);
		}

		Texture::~Texture() {
			BUFFALO_PROFILE_FUNC();
			GL::DeleteTextures(1, &handle);
		}

		void Texture::Bind(TextureTarget textureTarget) {
			BUFFALO_PROFILE_FUNC();
			GL::BindTexture(textureTarget, handle);
			target = textureTarget;
		}

		void Texture::SetData(TextureInternalFormat internalFormat, PixelFormat format, PixelDataType type, GLsizei width, GLsizei height, const GLvoid* data) {
			BUFFALO_PROFILE_FUNC();
			GL::TexImage2D(target, 0, internalFormat, width, height, format, type, data);
		}

		void Texture::SetMagFilter(FilterType filter) {
			BUFFALO_PROFILE_FUNC();
			GL::TexParameteri(target, TextureParameterName::TextureMagFilter, static_cast<GLint>(filter));
		}

		void Texture::SetMinFilter(FilterType filter) {
			BUFFALO_PROFILE_FUNC();
			GL::TexParameteri(target, TextureParameterName::TextureMinFilter, static_cast<GLint>(filter));
		}

		void Texture::Unbind() {
			BUFFALO_PROFILE_FUNC();
			GL::BindTexture(target, 0U);
			this->target = TextureTarget::NoTarget;
		}
	}
}