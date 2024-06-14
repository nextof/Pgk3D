#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <glad/glad.h>

class EBO
{
public:
    // ID referencyjny dla Obiektu Bufora Elementów (EBO)
    GLuint ID;

    /**
     * @brief Konstruktor, który generuje Obiekt Bufora Elementów (EBO) i ³¹czy go z danymi indeksów.
     *
     * @param indices WskaŸnik do tablicy danych indeksów.
     * @param size Rozmiar danych indeksów w bajtach.
     */
    EBO(GLuint* indices, GLsizeiptr size);

    /**
     * @brief Wi¹¿e (binduje) EBO.
     */
    void Bind();

    /**
     * @brief Odczepia (unbinduje) EBO.
     */
    void Unbind();

    /**
     * @brief Usuwa EBO.
     */
    void Delete();
};

#endif
