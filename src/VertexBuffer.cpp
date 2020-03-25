#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(GLenum type)
{
	this->buffer_id = 0;
	this->type =type; 
	glGenBuffers(1, &(this->buffer_id));
	this->Bind();
}

void VertexBuffer::BufferData(GLsizeiptr size, void* data, GLenum usage)
{
	this->Bind();
	glBufferData(this->type, size, data, usage);
}
VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &(this->buffer_id));
	this->Unbind();
}

void VertexBuffer::Bind()
{
	glBindBuffer(this->type, buffer_id);
}

void VertexBuffer::Unbind()
{
	glBindBuffer(this->type, 0);
}

void VertexBuffer::VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer)
{
	this->Bind(); 
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	glEnableVertexAttribArray(index);
}

