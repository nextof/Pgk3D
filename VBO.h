#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>

class VBO
{
public:
    // ID referencyjny dla Obiektu Bufora Wierzcho�k�w (VBO)
    GLuint ID;

    /**
     * @brief Konstruktor, kt�ry generuje Obiekt Bufora Wierzcho�k�w (VBO) i ��czy go z danymi wierzcho�k�w.
     *
     * @param vertices Wska�nik do tablicy danych wierzcho�k�w.
     * @param size Rozmiar danych wierzcho�k�w w bajtach.
     */
    VBO(GLfloat* vertices, GLsizeiptr size);

    /**
     * @brief Wi��e (binduje) VBO.
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
