#pragma once

#include "GL/glew.h"
#include <string>
#include "stb_image.h"

namespace GLGame
{
	using namespace std;

	class Texture
	{
	public:

		Texture()
		{
			m_clean_up = true;
			m_width = 0;
			m_height = 0;
			m_texture = 0;
			m_type = GL_TEXTURE_2D;
			m_intformat = GL_RGBA;
			m_BPP = 0;
		}

		~Texture()
		{
			glDeleteTextures(1, &m_texture);
		}

		void CreateTexture(string path, GLint internalformat = GL_RGBA, GLenum type = GL_TEXTURE_2D,
			GLenum min_filter = GL_NEAREST, GLenum mag_filter = GL_NEAREST,
			GLenum texwrap_s = GL_REPEAT, GLenum texwrap_t = GL_REPEAT, bool clean_up = true);

		inline int GetWidth() { return m_width; }
		inline int GetHeight() { return m_height; }
		inline void Bind(int slot = 0)
		{
			glActiveTexture(GL_TEXTURE0 + slot);
			glBindTexture(this->m_type, this->m_texture);
		}

		inline void Unbind() { glBindTexture(m_type, 0); };
		inline GLuint GetTextureID() { return m_texture; };

	private:

		bool m_clean_up;
		int m_width;
		int m_height;
		int m_BPP;
		GLint m_intformat;
		GLuint m_texture;
		GLenum m_type;
		string m_path;

	};
}