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
	 * @brief Konstruktor klasy Shader, który buduje program shaderowy na podstawie dwóch ró¿nych shaderów.
	 *
	 * @param vertexFile Œcie¿ka do pliku zawieraj¹cego kod shadera wierzcho³ków.
	 * @param fragmentFile Œcie¿ka do pliku zawieraj¹cego kod shadera fragmentów.
	 */
	Shader(const char* vertexFile, const char* fragmentFile);

	/**
	 * @brief Metoda aktywuj¹ca program shaderowy.
	 */
	void Activate();
	/**
	 * @brief Metoda usuwaj¹ca program shaderowy.
	 */
	void Delete();
	/**
	 * @brief Metoda ustawiaj¹ca flagê okreœlaj¹c¹ u¿ywanie tekstury w shaderze.
	 *
	 * @param useTexture Wartoœæ logiczna okreœlaj¹ca, czy u¿ywaæ tekstury (true) czy nie (false).
	 */
	void setUseTexture(bool useTexture);
private:
	/**
	 * @brief Metoda sprawdzaj¹ca, czy poszczególne shadery zosta³y skompilowane poprawnie.
	 *
	 * @param shader Identyfikator shadera (vertex, fragment lub program).
	 * @param type Typ shadera (VERTEX, FRAGMENT lub PROGRAM).
	 */
	void compileErrors(unsigned int shader, const char* type);
	
};


#endif