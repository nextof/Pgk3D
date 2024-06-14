#include"shaderClass.h"

/**
 * @brief Funkcja wczytuj¹ca zawartoœæ pliku tekstowego i zwracaj¹ca j¹ jako string.
 *
 * @param filename Œcie¿ka do pliku tekstowego.
 * @return Zawartoœæ pliku jako string.
 * @throw errno W przypadku problemu z otwarciem pliku, zg³asza numer b³êdu.
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
 * @brief Konstruktor klasy Shader, który buduje program shaderowy na podstawie dwóch ró¿nych shaderów.
 *
 * @param vertexFile Œcie¿ka do pliku zawieraj¹cego kod shadera wierzcho³ków.
 * @param fragmentFile Œcie¿ka do pliku zawieraj¹cego kod shadera fragmentów.
 */
Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	// Wczytanie zawartoœci plików vertexFile i fragmentFile jako stringi
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	// Konwersja Ÿróde³ shaderów na tablice znaków
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	// Utworzenie obiektu shadera wierzcho³ków i przypisanie mu Ÿród³a
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	// Sprawdzenie poprawnoœci kompilacji shadera wierzcho³ków
	compileErrors(vertexShader, "VERTEX");

	// Utworzenie obiektu shadera fragmentów i przypisanie mu Ÿród³a
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	// Sprawdzenie poprawnoœci kompilacji shadera fragmentów
	compileErrors(fragmentShader, "FRAGMENT");

	// Utworzenie programu shaderowego i z³¹czenie w nim shaderów wierzcho³ków i fragmentów
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	// Sprawdzenie poprawnoœci z³¹czenia shaderów w program shaderowy
	compileErrors(ID, "PROGRAM");

	// Usuniêcie niepotrzebnych ju¿ obiektów shaderów wierzcho³ków i fragmentów
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}
/**
 * @brief Metoda aktywuj¹ca program shaderowy.
 */
void Shader::Activate()
{
	glUseProgram(ID);
}

/**
 * @brief Metoda usuwaj¹ca program shaderowy.
 */
void Shader::Delete()
{
	glDeleteProgram(ID);
}
/**
 * @brief Metoda sprawdzaj¹ca, czy poszczególne shadery zosta³y skompilowane poprawnie.
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
 * @brief Metoda ustawiaj¹ca wartoœæ flagi okreœlaj¹cej u¿ywanie tekstury w shaderze.
 *
 * @param useTexture Wartoœæ logiczna okreœlaj¹ca, czy u¿ywaæ tekstury (true) czy nie (false).
 */
void Shader::setUseTexture(bool useTexture){
	glUniform1i(glGetUniformLocation(ID, "useTexture"), useTexture ? 1 : 0);
}