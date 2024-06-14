#include"VBO.h"

/**
	 * @brief Konstruktor tworz�cy obiekt bufora wierzcho�k�w (VBO) i ��cz�cy go z danymi wierzcho�k�w.
	 *
	 * @param vertices Wska�nik do danych wierzcho�k�w.
	 * @param size Rozmiar danych wierzcho�k�w (w bajtach).
	 */
VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}
/**
	 * @brief Metoda do powi�zywania obiektu VBO.
	 */
void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

/**
	 * @brief Metoda do odbierania powi�zanego obiektu VBO.
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