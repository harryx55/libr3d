#include "pch.h"
#include "OpenGLBuffers.h"



namespace R3D
{
	void VertexBuffer::AttachBuffer(void* data, int size, int count)
	{
		m_size = size;
		m_count = count;

		glGenBuffers(1, &m_vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), data, GL_STATIC_DRAW);
	}

	void VertexBuffer::DeleteBuffer() const
	{
		glDeleteBuffers(1, &m_vertexBuffer);
	}

	void VertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	}

	void VertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void IndexBuffer::AttachBuffer(void* data, int size)
	{
		m_size = size;

		glGenBuffers(1, &m_indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(float), data, GL_STATIC_DRAW);
	}

	void IndexBuffer::DeleteBuffer() const
	{
		glDeleteBuffers(1, &m_indexBuffer);
	}

	void IndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
	}

	void IndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void VertexArray::CreateVertexArray()
	{
		glGenVertexArrays(1, &m_vertexArray);
		glBindVertexArray(m_vertexArray);
	}

	void VertexArray::AddBuffer(VertexBuffer* buffer, unsigned int index)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, buffer->GetCount(), GL_FLOAT, GL_FALSE, 0, (void*)0);
	}

	void VertexArray::DeleteVertexArray() const
	{
		glDeleteVertexArrays(1, &m_vertexArray);
	}

	void VertexArray::Bind() const
	{
		glBindVertexArray(m_vertexArray);
	}

	void VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}
}
