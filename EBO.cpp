#include"EBO.h"


/**
 * @brief Konstruktor generuj�cy Elements Buffer Object (EBO) i ��cz�cy go z indeksami.
 *
 * @param indices Wska�nik na tablic� zawieraj�c� indeksy.
 * @param size Rozmiar danych do przekazania do bufora.
 */
EBO::EBO(GLuint* indices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

/**
 * @brief Metoda wi���ca (binduj�ca) EBO.
 */
void EBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

/**
 * @brief Metoda odwi�zuj�ca (unbinduj�ca) EBO.
 */
void EBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

/**
 * @brief Metoda usuwaj�ca EBO.
 */
void EBO::Delete()
{
	glDeleteBuffers(1, &ID);
}