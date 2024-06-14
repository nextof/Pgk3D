#include"VAO.h"

/**
	 * @brief Konstruktor tworz¹cy identyfikator obiektu VAO.
	 */
VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

/**
	 * @brief Metoda ³¹cz¹ca atrybut VBO, takie jak pozycja lub kolor, z obiektem VAO.
	 *
	 * @param VBO Referencja do obiektu bufora wierzcho³ków (VBO), do którego jest przypisany atrybut.
	 * @param layout Indeks atrybutu w programie shader.
	 * @param numComponents Liczba komponentów atrybutu (np. 3 dla wspó³rzêdnych xyz).
	 * @param type Typ danych atrybutu (np. GL_FLOAT dla danych typu float).
	 * @param stride Rozmiar bufora (w bajtach) miêdzy kolejnymi zestawami danych.
	 * @param offset Przesuniêcie w buforze, na którym zaczyna siê atrybut.
	 */
void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

/**
	 * @brief Metoda do powi¹zywania obiektu VAO.
	 */
void VAO::Bind()
{
	glBindVertexArray(ID);
}

/**
	 * @brief Metoda do odbierania powi¹zanego obiektu VAO.
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