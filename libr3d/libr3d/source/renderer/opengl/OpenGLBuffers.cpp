#include "OpenGLBuffers.h"

//
// vertex array and vertex attributes
//

void VertexArray::CreateVertexArray()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}

void VertexArray::BindVertexArray()
{
	glBindVertexArray(vao);
}

void VertexArray::UnbindVertexArray()
{
	glBindVertexArray(0);
}

void VertexArray::DestroyVertexArray()
{
	glDeleteVertexArrays(1, &vao);
}

void VertexArray::AttachAttributes(GLuint index, GLuint size, GLuint stride, GLuint offset)
{
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, sizeof(float) * stride, (void*)(sizeof(float) * offset));
}

//
// vertex buffer
//

void VertexBuffer::CreateBuffer(void* data, GLuint size)
{
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), data, GL_STATIC_DRAW);
}

void VertexBuffer::BindBuffer()
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);	
}

void VertexBuffer::UnbindBuffer()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::DestroyBuffer()
{
	glDeleteBuffers(1, &vbo);
}


//
// index buffer
//

void IndexBuffer::CreateBuffer(void* data, GLuint size)
{
	count = size;
	
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(GLuint), data, GL_STATIC_DRAW);
}

void IndexBuffer::BindBuffer()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);	
}

void IndexBuffer::UnbindBuffer()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::DestroyBuffer()
{
	glDeleteBuffers(1, &ibo);
}
