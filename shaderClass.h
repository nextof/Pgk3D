#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string get_file_contents(const char* filename);

class Shader
{
public:
	
	GLuint ID;///< ID programu shaderowego
	/**
	 * @brief Konstruktor klasy Shader, kt�ry buduje program shaderowy na podstawie dw�ch r�nych shader�w.
	 *
	 * @param vertexFile �cie�ka do pliku zawieraj�cego kod shadera wierzcho�k�w.
	 * @param fragmentFile �cie�ka do pliku zawieraj�cego kod shadera fragment�w.
	 */
	Shader(const char* vertexFile, const char* fragmentFile);

	/**
	 * @brief Metoda aktywuj�ca program shaderowy.
	 */
	void Activate();
	/**
	 * @brief Metoda usuwaj�ca program shaderowy.
	 */
	void Delete();
	/**
	 * @brief Metoda ustawiaj�ca flag� okre�laj�c� u�ywanie tekstury w shaderze.
	 *
	 * @param useTexture Warto�� logiczna okre�laj�ca, czy u�ywa� tekstury (true) czy nie (false).
	 */
	void setUseTexture(bool useTexture);
private:
	/**
	 * @brief Metoda sprawdzaj�ca, czy poszczeg�lne shadery zosta�y skompilowane poprawnie.
	 *
	 * @param shader Identyfikator shadera (vertex, fragment lub program).
	 * @param type Typ shadera (VERTEX, FRAGMENT lub PROGRAM).
	 */
	void compileErrors(unsigned int shader, const char* type);
	
};


#endif