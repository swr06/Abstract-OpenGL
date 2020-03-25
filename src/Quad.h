#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "IndexBuffer.h"

#include <iostream>
#include <string>
#include <vector>

/*
 start point (depicted by "*")
  *_____________________
  |                    |
  |                    |
  |                    |
  |                    |
  |____________________* end point (depicted by "*")


  pt.1                 pt.2
  ______________________
  |                    |
  |                    |
  |                    |
  |                    |
  |____________________|

  pt.3                 pt.4
*/


struct quad
{
	GLfloat p1x; 
	GLfloat p1y; 

	GLfloat p2x; 
	GLfloat p2y; 

	GLfloat p3x; 
	GLfloat p3y; 

	GLfloat p4x; 
	GLfloat p4y;
};

class Quad
{
	public : 

	Quad(GLfloat pt_1x, GLfloat pt_1y, GLfloat pt_2x, GLfloat pt_2y)
	{
		GLuint vertices[6] =
		{
				2, 3, 0, // First triangle
				3, 1, 0 // Second triangle
		};
 
		quad_index.BufferData(sizeof(vertices), vertices, GL_STATIC_DRAW);
		quad_index.Unbind(); 

		this->quad_coords.p1x = pt_1x;
		this->quad_coords.p1y = pt_1y;

		this->quad_coords.p2x = pt_2x; 
		this->quad_coords.p2y = pt_1y; 

		this->quad_coords.p3x = pt_1x;
		this->quad_coords.p3y = pt_2y;

		this->quad_coords.p4x = pt_2x;
		this->quad_coords.p4y = pt_2y;
	};

	inline quad GetCoordinates()
	{
		return this->quad_coords; 
	}

	inline void Use()
	{
		quad_index.Bind();
	}

	private : 

	quad quad_coords;
	IndexBuffer quad_index; 
};

