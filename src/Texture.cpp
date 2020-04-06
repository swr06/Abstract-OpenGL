#include "Texture.h"

namespace GLGame
{
	void Texture::CreateTexture(string path, GLint internalformat, GLenum type, GLenum min_filter, GLenum mag_filter, GLenum texwrap_s, GLenum texwrap_t, bool clean_up)
	{
		stbi_set_flip_vertically_on_load(1);
		m_clean_up = clean_up;
		m_type = type;
		m_path = path;
		m_intformat = internalformat;

		glGenTextures(1, &m_texture);
		glBindTexture(type, m_texture);
		glTexParameteri(type, GL_TEXTURE_WRAP_S, texwrap_s);
		glTexParameteri(type, GL_TEXTURE_WRAP_T, texwrap_t);

		glTexParameteri(type, GL_TEXTURE_MIN_FILTER, min_filter);
		glTexParameteri(type, GL_TEXTURE_MAG_FILTER, mag_filter);

		//unsigned char* image = SOIL_load_image(path.c_str(), &m_width, &m_height, 0, SOIL_LOAD_RGBA);
		unsigned char* image = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);
		glTexImage2D(type, 0, internalformat, m_width, m_height, 0, internalformat, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(type);

		if (image && clean_up)
		{
			//SOIL_free_image_data(image);
			stbi_image_free(image);
			glBindTexture(type, 0);
		}
	}
}