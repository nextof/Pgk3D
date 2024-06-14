#include"EBO.h"


/**
 * @brief Konstruktor generuj¹cy Elements Buffer Object (EBO) i ³¹cz¹cy go z indeksami.
 *
 * @param indices WskaŸnik na tablicê zawieraj¹c¹ indeksy.
 * @param size Rozmiar danych do przekazania do bufora.
 */
EBO::EBO(GLuint* indices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

/**
 * @brief Metoda wi¹¿¹ca (binduj¹ca) EBO.
 */
void EBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

/**
 * @brief Metoda odwi¹zuj¹ca (unbinduj¹ca) EBO.
 */
void EBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

/**
 * @brief Metoda usuwaj¹ca EBO.
 */
void EBO::Delete()
{
	glDeleteBuffers(1, &ID);
}