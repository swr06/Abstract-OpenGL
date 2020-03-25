#include "Shader.h"

Shader::~Shader()
{
	glUseProgram(0); 
}

GLuint Shader::CreateShaderProgram(const string vertex_pth, const string fragment_pth)
{
	stringstream v_cont;
	stringstream f_cont;
	string vertex_cont; 
	string frag_cont; 
	ifstream vertex_file;
	ifstream frag_file;

	// error displaying
	GLint success;
	GLchar infoLog[512];

	// final program
	GLuint program; 

	vertex_file.exceptions(ifstream::badbit | ifstream::failbit);
	frag_file.exceptions(ifstream::badbit | ifstream::failbit);
	
	vertex_file.open(vertex_pth, ios::in);
	frag_file.open(fragment_pth, ios::in); 

	if (vertex_file.good() && frag_file.good())
	{
		v_cont << vertex_file.rdbuf();
		f_cont << frag_file.rdbuf();
		vertex_cont = v_cont.str(); 
		frag_cont = f_cont.str();

		vertex_file.close();
		frag_file.close();

		GLuint vertex_shader; 
		GLuint fragment_shader; 

		vertex_shader = glCreateShader(GL_VERTEX_SHADER); 
		fragment_shader = glCreateShader(GL_FRAGMENT_SHADER); 
		const char* vchar_data = vertex_cont.c_str();
		glShaderSource(vertex_shader, 1, &vchar_data, 0);
		const char* fchar_data = frag_cont.c_str();
		glShaderSource(fragment_shader, 1, &fchar_data, 0);
		glCompileShader(vertex_shader);

		glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED  \n  " << infoLog << std::endl;
		}

		glCompileShader(fragment_shader); 
		glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED  \n  " << infoLog << std::endl;
		}

		program = glCreateProgram(); 
		glAttachShader(program, vertex_shader); 
		glAttachShader(program, fragment_shader);
		glLinkProgram(program);

		glGetProgramiv(program, GL_LINK_STATUS, &success);

		if (!success) 
		{
			glGetProgramInfoLog(program, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);
	}

	this->Program = program; 
	return program; 
}

GLuint Shader::GetProgramID()
{
	return Program; 
}

