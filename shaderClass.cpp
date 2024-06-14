#include"shaderClass.h"

/**
 * @brief Funkcja wczytuj�ca zawarto�� pliku tekstowego i zwracaj�ca j� jako string.
 *
 * @param filename �cie�ka do pliku tekstowego.
 * @return Zawarto�� pliku jako string.
 * @throw errno W przypadku problemu z otwarciem pliku, zg�asza numer b��du.
 */
std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

/**
 * @brief Konstruktor klasy Shader, kt�ry buduje program shaderowy na podstawie dw�ch r�nych shader�w.
 *
 * @param vertexFile �cie�ka do pliku zawieraj�cego kod shadera wierzcho�k�w.
 * @param fragmentFile �cie�ka do pliku zawieraj�cego kod shadera fragment�w.
 */
Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	// Wczytanie zawarto�ci plik�w vertexFile i fragmentFile jako stringi
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	// Konwersja �r�de� shader�w na tablice znak�w
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	// Utworzenie obiektu shadera wierzcho�k�w i przypisanie mu �r�d�a
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	// Sprawdzenie poprawno�ci kompilacji shadera wierzcho�k�w
	compileErrors(vertexShader, "VERTEX");

	// Utworzenie obiektu shadera fragment�w i przypisanie mu �r�d�a
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	// Sprawdzenie poprawno�ci kompilacji shadera fragment�w
	compileErrors(fragmentShader, "FRAGMENT");

	// Utworzenie programu shaderowego i z��czenie w nim shader�w wierzcho�k�w i fragment�w
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	// Sprawdzenie poprawno�ci z��czenia shader�w w program shaderowy
	compileErrors(ID, "PROGRAM");

	// Usuni�cie niepotrzebnych ju� obiekt�w shader�w wierzcho�k�w i fragment�w
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}
/**
 * @brief Metoda aktywuj�ca program shaderowy.
 */
void Shader::Activate()
{
	glUseProgram(ID);
}

/**
 * @brief Metoda usuwaj�ca program shaderowy.
 */
void Shader::Delete()
{
	glDeleteProgram(ID);
}
/**
 * @brief Metoda sprawdzaj�ca, czy poszczeg�lne shadery zosta�y skompilowane poprawnie.
 *
 * @param shader Identyfikator shadera (vertex, fragment lub program).
 * @param type Typ shadera (VERTEX, FRAGMENT lub PROGRAM).
 */
void Shader::compileErrors(unsigned int shader, const char* type)
{
	GLint hasCompiled;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
}
/**
 * @brief Metoda ustawiaj�ca warto�� flagi okre�laj�cej u�ywanie tekstury w shaderze.
 *
 * @param useTexture Warto�� logiczna okre�laj�ca, czy u�ywa� tekstury (true) czy nie (false).
 */
void Shader::setUseTexture(bool useTexture){
	glUniform1i(glGetUniformLocation(ID, "useTexture"), useTexture ? 1 : 0);
}