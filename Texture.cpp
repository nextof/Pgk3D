#include "Texture.h"

/**
 * @brief Konstruktor klasy Texture, inicjalizuje tekstur� na podstawie obrazka z pliku.
 *
 * @param image �cie�ka do pliku obrazka tekstury.
 * @param texType Typ tekstury OpenGL (np. GL_TEXTURE_2D).
 * @param slot Slot tekstury OpenGL.
 * @param format Format obrazka tekstury.
 * @param pixelType Typ piksela tekstury.
 */
Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
{
    // Przypisanie typu tekstury do obiektu tekstury
    type = texType;

    // Wczytanie obrazka
    int widthImg, heightImg, numColCh;
    stbi_set_flip_vertically_on_load(true); // Obr�cenie obrazka (g�ra do do�u)
    unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

    // Generowanie obiektu tekstury OpenGL
    glGenTextures(1, &ID);
    glActiveTexture(slot);
    glBindTexture(texType, ID);

    // Konfiguracja filtr�w tekstury
    glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Konfiguracja powtarzania tekstury
    glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Przypisanie obrazka do obiektu tekstury OpenGL
    glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);
    glGenerateMipmap(texType);

    // Zwolnienie pami�ci po obrazku
    stbi_image_free(bytes);

    // Odbindowanie obiektu tekstury OpenGL
    glBindTexture(texType, 0);
}

/**
 * @brief Przypisuje jednostk� tekstury do okre�lonego uniformu w shaderze.
 *
 * @param shader Referencja do obiektu shadera.
 * @param uniform Nazwa zmiennej uniformu w shaderze.
 * @param unit Numer jednostki tekstury.
 */
void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{
    GLuint texUni = glGetUniformLocation(shader.ID, uniform);
    shader.Activate(); // Aktywacja shadera przed zmian� warto�ci uniformu
    glUniform1i(texUni, unit); // Przypisanie warto�ci jednostki do uniformu
}

/**
 * @brief Wi��e obiekt tekstury OpenGL.
 */
void Texture::Bind()
{
    glBindTexture(type, ID);
}

/**
 * @brief Odbindowuje obiekt tekstury OpenGL.
 */
void Texture::Unbind()
{
    glBindTexture(type, 0);
}

/**
 * @brief Usuwa obiekt tekstury OpenGL z pami�ci.
 */
void Texture::Delete()
{
    glDeleteTextures(1, &ID);
}
