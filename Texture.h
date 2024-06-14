#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "shaderClass.h"

/**
 * @brief Klasa reprezentuj¹ca teksturê.
 */
class Texture
{
public:
    GLuint ID; ///< ID tekstury
    GLenum type; ///< Typ tekstury

    /**
     * @brief Konstruktor klasy Texture.
     *
     * @param image Œcie¿ka do pliku obrazka tekstury.
     * @param texType Typ tekstury OpenGL (np. GL_TEXTURE_2D).
     * @param slot Slot tekstury OpenGL.
     * @param format Format obrazka tekstury.
     * @param pixelType Typ piksela tekstury.
     */
    Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

    /**
     * @brief Przypisuje jednostkê tekstury do danego shadera.
     *
     * @param shader Referencja do obiektu shadera.
     * @param uniform Nazwa zmiennej jednostki tekstury w shaderze.
     * @param unit Numer jednostki tekstury.
     */
    void texUnit(Shader& shader, const char* uniform, GLuint unit);

    /**
     * @brief Wi¹¿e teksturê.
     */
    void Bind();

    /**
     * @brief Odwi¹zuje teksturê.
     */
    void Unbind();

    /**
     * @brief Usuwa teksturê z pamiêci.
     */
    void Delete();
};

#endif
