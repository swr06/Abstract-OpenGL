#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Texture.h"
#include "Quad.h"

#include <iostream>
#include <vector>

class Renderer
{
	public:

	Renderer()
	{

	};

	void DrawTriangle(VertexArray& VAO, IndexBuffer& IBO, Shader &ShaderProgram)
	{
		VAO.Bind(); 
		IBO.Bind();
		ShaderProgram.Use(); 
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	inline void Clear()
	{ 
		glClear(GL_COLOR_BUFFER_BIT);
	}
};
