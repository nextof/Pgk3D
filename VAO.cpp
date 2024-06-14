#include"VAO.h"

/**
	 * @brief Konstruktor tworz�cy identyfikator obiektu VAO.
	 */
VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

/**
	 * @brief Metoda ��cz�ca atrybut VBO, takie jak pozycja lub kolor, z obiektem VAO.
	 *
	 * @param VBO Referencja do obiektu bufora wierzcho�k�w (VBO), do kt�rego jest przypisany atrybut.
	 * @param layout Indeks atrybutu w programie shader.
	 * @param numComponents Liczba komponent�w atrybutu (np. 3 dla wsp�rz�dnych xyz).
	 * @param type Typ danych atrybutu (np. GL_FLOAT dla danych typu float).
	 * @param stride Rozmiar bufora (w bajtach) mi�dzy kolejnymi zestawami danych.
	 * @param offset Przesuni�cie w buforze, na kt�rym zaczyna si� atrybut.
	 */
void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

/**
	 * @brief Metoda do powi�zywania obiektu VAO.
	 */
void VAO::Bind()
{
	glBindVertexArray(ID);
}

/**
	 * @brief Metoda do odbierania powi�zanego obiektu VAO.
	 */
void VAO::Unbind()
{
	glBindVertexArray(0);
}

/**
	 * @brief Metoda do usuwania obiektu VAO.
	 */
void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}