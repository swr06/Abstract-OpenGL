#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std; 

class Shader
{
	public : 
	
	~Shader();

	GLuint CreateShaderProgram(const string vertex_pth, const string fragment_pth);
	GLuint GetProgramID(); 
	inline void Use()
	{
		glUseProgram(this->Program);
	}



	private :
	
	GLuint Program; 
};

