#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>

class VBO
{
public:
    // ID referencyjny dla Obiektu Bufora Wierzcho³ków (VBO)
    GLuint ID;

    /**
     * @brief Konstruktor, który generuje Obiekt Bufora Wierzcho³ków (VBO) i ³¹czy go z danymi wierzcho³ków.
     *
     * @param vertices WskaŸnik do tablicy danych wierzcho³ków.
     * @param size Rozmiar danych wierzcho³ków w bajtach.
     */
    VBO(GLfloat* vertices, GLsizeiptr size);

    /**
     * @brief Wi¹¿e (binduje) VBO.
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
