#include"VBO.h"

/**
	 * @brief Konstruktor tworzący obiekt bufora wierzchołków (VBO) i łączący go z danymi wierzchołków.
	 *
	 * @param vertices Wskaźnik do danych wierzchołków.
	 * @param size Rozmiar danych wierzchołków (w bajtach).
	 */
VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}
/**
	 * @brief Metoda do powiązywania obiektu VBO.
	 */
void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

/**
	 * @brief Metoda do odbierania powiązanego obiektu VBO.
	 */
void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/**
	 * @brief Metoda do usuwania obiektu VBO.
	 */
void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}