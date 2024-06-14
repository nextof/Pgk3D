#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <glad/glad.h>

class EBO
{
public:
    // ID referencyjny dla Obiektu Bufora Element�w (EBO)
    GLuint ID;

    /**
     * @brief Konstruktor, kt�ry generuje Obiekt Bufora Element�w (EBO) i ��czy go z danymi indeks�w.
     *
     * @param indices Wska�nik do tablicy danych indeks�w.
     * @param size Rozmiar danych indeks�w w bajtach.
     */
    EBO(GLuint* indices, GLsizeiptr size);

    /**
     * @brief Wi��e (binduje) EBO.
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
