#pragma once
#include "pch.h"
#include <glad/glad.h>


namespace R3D
{
	class VertexBuffer
	{
	private:
		unsigned int m_vertexBuffer;
		unsigned int m_size;
		unsigned int m_count;

	public:
		VertexBuffer();

		void AttachBuffer(void* data, int size, int);
		void Bind() const;
		void Unbind() const;
		void DeleteBuffer() const;

		inline const unsigned int GetSize() const { return m_size; }
		inline const unsigned int GetCount() const { return m_count; }
	};


	class IndexBuffer
	{
	private:
		unsigned int m_indexBuffer;
		unsigned int m_size;

	public:
		IndexBuffer();

		void AttachBuffer(void*, int);
		void Bind() const;
		void Unbind() const;
		void DeleteBuffer() const;

		inline const unsigned int GetSize() const { return m_size; }
	};


	class VertexArray
	{
	private:
		unsigned int m_vertexArray;
		static unsigned int m_offset;

	public:
		VertexArray();

		void CreateVertexArray();
		void AddBuffer(unsigned int, size_t, unsigned int);
		void DeleteVertexArray() const;
		void Bind() const;
		void Unbind() const;
	};
}