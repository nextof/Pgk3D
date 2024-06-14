#include"VBO.h"

/**
	 * @brief Konstruktor tworz¹cy obiekt bufora wierzcho³ków (VBO) i ³¹cz¹cy go z danymi wierzcho³ków.
	 *
	 * @param vertices WskaŸnik do danych wierzcho³ków.
	 * @param size Rozmiar danych wierzcho³ków (w bajtach).
	 */
VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}
/**
	 * @brief Metoda do powi¹zywania obiektu VBO.
	 */
void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

/**
	 * @brief Metoda do odbierania powi¹zanego obiektu VBO.
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