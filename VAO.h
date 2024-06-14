#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include <glad/glad.h>
#include "VBO.h"

class VAO
{
public:
    // ID referencyjny dla Obiektu Tablicy Wierzcho�k�w (VAO)
    GLuint ID;

    /**
     * @brief Konstruktor generuj�cy identyfikator VAO.
     */
    VAO();

    /**
     * @brief ��czy atrybut VBO, takie jak pozycja lub kolor, z VAO.
     *
     * @param VBO Referencja do obiektu VBO, z kt�rego pobierane s� dane.
     * @param layout Numer indeksu atrybutu shadera, do kt�rego ma by� przypisany ten atrybut.
     * @param numComponents Liczba sk�adowych dla tego atrybutu (np. 3 dla pozycji XYZ).
     * @param type Typ danych OpenGL dla tego atrybutu (np. GL_FLOAT).
     * @param stride Rozmiar pojedynczego wierzcho�ka w bajtach.
     * @param offset Przesuni�cie do tego atrybutu w wierzcho�ku.
     */
    void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

    /**
     * @brief Wi��e (binduje) VAO.
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
