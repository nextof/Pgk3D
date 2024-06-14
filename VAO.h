#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include <glad/glad.h>
#include "VBO.h"

class VAO
{
public:
    // ID referencyjny dla Obiektu Tablicy Wierzcho³ków (VAO)
    GLuint ID;

    /**
     * @brief Konstruktor generuj¹cy identyfikator VAO.
     */
    VAO();

    /**
     * @brief £¹czy atrybut VBO, takie jak pozycja lub kolor, z VAO.
     *
     * @param VBO Referencja do obiektu VBO, z którego pobierane s¹ dane.
     * @param layout Numer indeksu atrybutu shadera, do którego ma byæ przypisany ten atrybut.
     * @param numComponents Liczba sk³adowych dla tego atrybutu (np. 3 dla pozycji XYZ).
     * @param type Typ danych OpenGL dla tego atrybutu (np. GL_FLOAT).
     * @param stride Rozmiar pojedynczego wierzcho³ka w bajtach.
     * @param offset Przesuniêcie do tego atrybutu w wierzcho³ku.
     */
    void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

    /**
     * @brief Wi¹¿e (binduje) VAO.
     */
    void Bind();

    /**
     * @brief Odczepia (unbinduje) VAO.
     */
    void Unbind();

    /**
     * @brief Usuwa VAO.
     */
    void Delete();
};

#endif
