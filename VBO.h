#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>

class VBO
{
public:
    // ID referencyjny dla Obiektu Bufora Wierzchołków (VBO)
    GLuint ID;

    /**
     * @brief Konstruktor, który generuje Obiekt Bufora Wierzchołków (VBO) i łączy go z danymi wierzchołków.
     *
     * @param vertices Wskaźnik do tablicy danych wierzchołków.
     * @param size Rozmiar danych wierzchołków w bajtach.
     */
    VBO(GLfloat* vertices, GLsizeiptr size);

    /**
     * @brief Wiąże (binduje) VBO.
     */
    void Bind();

    /**
     * @brief Odczepia (unbinduje) VBO.
     */
    void Unbind();

    /**
     * @brief Usuwa VBO.
     */
    void Delete();
};

#endif
