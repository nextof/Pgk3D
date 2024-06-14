#include "Engine.h"
#include <vector>
#include <cmath>
#define M_PI 3.14159265358979323846 ///< Definicja wartości PI.


bool draw1 = true;
bool draw2 = false;
bool draw3 = false;
int fps = 60;



/**
 * @brief Funkcja generująca wierzchołki kuli.
 *
 * Generuje wierzchołki kuli o podanym promieniu i podanej ilości sektorów i stosów.
 *
 * @param radius Promień kuli.
 * @param sectorCount Liczba sektorów.
 * @param stackCount Liczba stosów.
 * @return std::vector<GLfloat> Wektor zawierający współrzędne wierzchołków.
 */
std::vector<GLfloat> generateSphereVertices(float radius, int sectorCount, int stackCount) {
	std::vector<GLfloat> vertices;
	float x, y, z, xy;
	float nx, ny, nz, lengthInv = 1.0f / radius;
	float s, t;

	float sectorStep = 2 * M_PI / sectorCount;
	float stackStep = M_PI / stackCount;
	float sectorAngle, stackAngle;

	for (int i = 0; i <= stackCount; ++i) {
		stackAngle = M_PI / 2 - i * stackStep;
		xy = radius * cosf(stackAngle);
		z = radius * sinf(stackAngle);

		for (int j = 0; j <= sectorCount; ++j) {
			sectorAngle = j * sectorStep;

			x = xy * cosf(sectorAngle) - 4.0f; // Przesunięcie w lewo o 4 jednostki
			y = xy * sinf(sectorAngle);
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);

			nx = x * lengthInv;
			ny = y * lengthInv;
			nz = z * lengthInv;
			vertices.push_back(nx);
			vertices.push_back(ny);
			vertices.push_back(nz);

			s = (float)j / sectorCount;
			t = (float)i / stackCount;
			vertices.push_back(s);
			vertices.push_back(t);
		}
	}

	return vertices;
}

/**
 * @brief Funkcja generująca indeksy kuli.
 *
 * Generuje indeksy wierzchołków kuli na podstawie liczby sektorów i stosów.
 *
 * @param sectorCount Liczba sektorów.
 * @param stackCount Liczba stosów.
 * @return std::vector<GLuint> Wektor zawierający indeksy wierzchołków.
 */
std::vector<GLuint> generateSphereIndices(int sectorCount, int stackCount) {
	std::vector<GLuint> indices;
	int k1, k2;
	for (int i = 0; i < stackCount; ++i) {
		k1 = i * (sectorCount + 1);
		k2 = k1 + sectorCount + 1;

		for (int j = 0; j < sectorCount; ++j, ++k1, ++k2) {
			if (i != 0) {
				indices.push_back(k1);
				indices.push_back(k2);
				indices.push_back(k1 + 1);
			}

			if (i != (stackCount - 1)) {
				indices.push_back(k1 + 1);
				indices.push_back(k2);
				indices.push_back(k2 + 1);
			}
		}
	}

	return indices;
}

// Sześcian
GLfloat cubeArray[] = {
	// przód
	-0.5f+4.0f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,            // 0
	0.5f + 4.0f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,             // 1
	0.5f + 4.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,              // 2
	-0.5f + 4.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,             // 3

	// tył								   
	-0.5f + 4.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,            // 4
	0.5f + 4.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,             // 5
	0.5f + 4.0f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,              // 6
	-0.5f + 4.0f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,             // 7

	// lewo						   
	-0.5f + 4.0f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,            // 8
	-0.5f + 4.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,             // 9
	-0.5f + 4.0f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,              // 10
	-0.5f + 4.0f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f,             // 11

	// prawo							   
	0.5f + 4.0f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f,            // 12
	0.5f + 4.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,             // 13
	0.5f + 4.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f,              // 14
	0.5f + 4.0f, -0.5f, 0.5f, 1.0f, 1.0f, 0.0f,             // 15

	// tył							   
	-0.5f + 4.0f, -0.5f, 0.5f, 1.0f, 0.0f, 1.0f,            // 16
	0.5f + 4.0f, -0.5f, 0.5f, 1.0f, 0.0f, 1.0f,             // 17
	0.5f + 4.0f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f,              // 18
	-0.5f + 4.0f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f,             // 19

	// dół						   
	-0.5f + 4.0f, -0.5f, 0.5f, 0.0f, 1.0f, 1.0f,            // 20
	0.5f + 4.0f, -0.5f, 0.5f, 0.0f, 1.0f, 1.0f,             // 21
	0.5f + 4.0f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f,            // 22
	-0.5f + 4.0f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f,           // 23
};

GLuint cubeVertexIndices[] = {
	// przód
	0, 1, 2, // pierwszy trójkąt
	2, 3, 0, // drugi trójkąt

	// góra
	4, 5, 6, // pierwszy trójkąt
	6, 7, 4, // drugi trójkąt

	// lewo
	8, 9, 10,  // pierwszy trójkąt
	10, 11, 8, // drugi trójkąt

	// prawo
	14, 13, 12, // pierwszy trójkąt
	12, 15, 14, // drugi trójkąt

	// tył
	18, 17, 16, // pierwszy trójkąt
	16, 19, 18, // drugi trójkąt

	// dół
	20, 21, 22, // pierwszy trójkąt
	22, 23, 20  // drugi trójkąt
};
// Wierzchołki trójkąta
GLfloat triangleVertices[] = {
	//     Współrzedne              /        kolor         /    texturykordy   /        światło       
	-0.5f + 3.0f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,    0.0f, 0.0f,      0.0f, -1.0f, 0.0f, // 1
	-0.5f + 3.0f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,    0.0f, 5.0f,      0.0f, -1.0f, 0.0f, // 2
	 0.5f + 3.0f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,    5.0f, 5.0f,      0.0f, -1.0f, 0.0f, // 3
	 0.5f + 3.0f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,    5.0f, 0.0f,      0.0f, -1.0f, 0.0f, // 4
	 0.0f + 3.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,    2.5f, 5.0f,      0.0f,  0.0f, 1.0f // 5
};

// Indeksy trójkąta
GLuint triangleIndices[] = {
	0, 1, 4, // Pierwszy trójkąt
	1, 2, 4, // Drugi trójkąt
	2, 3, 4, // Trzeci trójkąt
	3, 0, 4, // Czwarty trójkąt
	0, 1, 2, // Podstawa trójkąta - pierwszy trójkąt
	2, 3, 0  // Podstawa trójkąta - drugi trójkąt
};


// Wierzchołki piramidy
GLfloat vertices[] =
{
	//     Współrzedne              /        kolor         /    texturykordy   /        światło 
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, -1.0f, 0.0f, // DÓŁ
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 5.0f,      0.0f, -1.0f, 0.0f, // DÓŁ
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 5.0f,      0.0f, -1.0f, 0.0f, //DÓŁ
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, -1.0f, 0.0f, // DÓŁ

	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // LEWO
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // LEWO
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,     -0.8f, 0.5f,  0.0f, // LEWO

	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f, -0.8f, // TYŁ
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.0f, 0.5f, -0.8f, // TYŁ
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f, -0.8f, // TYŁ

	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.8f, 0.5f,  0.0f, // PRAWO
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.8f, 0.5f,  0.0f, // PRAWO
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.8f, 0.5f,  0.0f, // PRAWO

	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f,  0.8f, // FRONT
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, 0.5f,  0.8f, // FRONT
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f,  0.8f  // FRONT
};

// Indeksy piramidy
GLuint indices[] =
{
	0, 1, 2, // DÓŁ
	0, 2, 3, // DÓŁ
	4, 6, 5, // LEWO
	7, 9, 8, // TYŁ
	10, 12, 11, // PRAWO
	13, 15, 14 // FRONT
};

GLfloat lightVertices[] =
{ //     WSPOŁRZDNE     //
	-0.1f, -0.1f,  0.1f,
	-0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f,  0.1f,
	-0.1f,  0.1f,  0.1f,
	-0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f,  0.1f
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

/**
	 * @brief Konstruktor klasy Engine.
	 *
	 * Inicjalizuje okno GLFW i ustawia profil OpenGL CORE.
	 *
	 * @param width Szerokość okna.
	 * @param height Wysokość okna.
	 */
Engine::Engine(int width, int height)
	: width(width), height(height)
{
	// Inicializacja GLFW
	glfwInit();

	// Ustawienie wersji GFLW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Ustawienie profilu CORE
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Tworzenie okna width,height i nazwa
	window = glfwCreateWindow(width, height, "Silnik3D", NULL, NULL);

	// Sprawdzanie czy okno zostało poprawnie utworzone
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	// Ładowanie okna
	glfwMakeContextCurrent(window);

	//Ładowanie GLAD 
	gladLoadGL();
	// Określanie Viewportu
	glViewport(0, 0, width, height);


	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Callbacki dla klawiszy
	glfwSetKeyCallback(window, key_callback);
}
/**
	 * @brief Destruktor klasy Engine.
	 *
	 * Zwalnia zasoby związane z oknem GLFW.
	 */
Engine::~Engine()
{
	// Usuwanie okna przed zakończeniem programu
	glfwDestroyWindow(window);
	// Wyłączenie GLFW przed zakończeniem programu
	glfwTerminate();
}
/**
	 * @brief Metoda uruchamiająca silnik.
	 *
	 * Tworzy obiekty VAO, VBO i EBO dla różnych kształtów.
	 */
void Engine::run()
{
	// Generowanie Shadera
	Shader shaderProgram("default.vert", "default.frag");

	// Generowanie wierzchołków i indeksów dla kuli
	std::vector<GLfloat> sphereVertices = generateSphereVertices(1.0f, 36, 18);
	std::vector<GLuint> sphereIndices = generateSphereIndices(36, 18);


	// Tworzenie obiektu
	VAO VAO1;
	VAO1.Bind();
	// Generowanie Vertex Buffer Object (VBO) i linkowanie go do wierzchołków
	VBO VBO1(vertices, sizeof(vertices));
	// Generowanie Element Buffer Object (EBO) i linkowanie go do indeksów
	EBO EBO1(indices, sizeof(indices));
	// Linkowanie atrybutów VBO, takich jak współrzędne i kolory, do VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	// Odbindowanie, aby uniknąć przypadkowej modyfikacji
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Tworzenie kuli
	VAO VAOSphere;
	VAOSphere.Bind();

	VBO VBOSphere(sphereVertices.data(), sphereVertices.size() * sizeof(GLfloat));
	EBO EBOSphere(sphereIndices.data(), sphereIndices.size() * sizeof(GLuint));
	// Linkowanie atrybutów VBO, takich jak współrzędne i kolory, do VAO
	VAOSphere.LinkAttrib(VBOSphere, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAOSphere.LinkAttrib(VBOSphere, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAOSphere.LinkAttrib(VBOSphere, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Odbindowanie, aby uniknąć przypadkowej modyfikacji
	VAOSphere.Unbind();
	VBOSphere.Unbind();
	EBOSphere.Unbind();


	//Tworzenie trójkąta
	VAO VAOTriangle;
	VAOTriangle.Bind();

	VBO VBOTriangle(triangleVertices, sizeof(triangleVertices));
	EBO EBOTriangle(triangleIndices, sizeof(triangleIndices));
	// Linkowanie atrybutów VBO, takich jak współrzędne i kolory, do VAO
	VAOTriangle.LinkAttrib(VBOTriangle, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAOTriangle.LinkAttrib(VBOTriangle, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAOTriangle.LinkAttrib(VBOTriangle, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAOTriangle.LinkAttrib(VBOTriangle, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	// Odbindowanie, aby uniknąć przypadkowej modyfikacji
	VAOTriangle.Unbind();
	VBOTriangle.Unbind();
	EBOTriangle.Unbind();



	// Generowanie Vertex Array Object (VAO) i jego wiązanie
	VAO VAOCube;
	VAOCube.Bind();

	VBO VBOCube(cubeArray, sizeof(cubeArray));

	EBO EBOCube(cubeVertexIndices, sizeof(cubeVertexIndices));

	// Linkowanie atrybutów VBO, takich jak współrzędne i kolory, do VAO
	VAOCube.LinkAttrib(VBOCube, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAOCube.LinkAttrib(VBOCube, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	VAOCube.LinkAttrib(VBOCube, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAOCube.LinkAttrib(VBOCube, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAOCube.Unbind();
	VBOCube.Unbind();
	EBOCube.Unbind();



	// Shader dla sześcianu światła
	Shader lightShader("light.vert", "light.frag");
	// Generowanie Vertex Array Object (VAO) i jego wiązanie
	VAO lightVAO;
	lightVAO.Bind();
	// Generowanie Vertex Buffer Object (VBO) i linkowanie go do wierzchołków
	VBO lightVBO(lightVertices, sizeof(lightVertices));
	// Generowanie Element Buffer Object (EBO) i linkowanie go do indeksów
	EBO lightEBO(lightIndices, sizeof(lightIndices));
	// Linkowanie atrybutów VBO, takich jak współrzędne i kolory, do VAO
	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	// Odbindowanie, aby uniknąć przypadkowej modyfikacji
	lightVAO.Unbind();
	lightVBO.Unbind();
	lightEBO.Unbind();


	// Ustawienie koloru światła i pozycji
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 1.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	// Ustawienie piramidy 
	glm::vec3 pyramidPos = glm::vec3(1.0f, 0.0f, 1.0f);
	glm::mat4 pyramidModel = glm::mat4(1.0f);
	pyramidModel = glm::translate(pyramidModel, pyramidPos);

	// Aktualizacja macierzy modelu dla trójkąta
	glm::vec3 trianglePos = glm::vec3(3.0f, 0.0f, 0.0f);
	glm::mat4 triangleModel = glm::mat4(1.0f);
	triangleModel = glm::translate(triangleModel, trianglePos);

	// Aktualizacja macierzy modelu dla trójkąta
	glm::vec3 cubePos = glm::vec3(3.0f, 0.0f, 5.0f);
	glm::mat4 cubeModel = glm::mat4(1.0f);
	cubeModel = glm::translate(cubeModel, cubePos);

	// Aktywacja shadera dla sześcianu światła
	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

	// Aktywacja głównego shadera programu
	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);



	// Ścieżka do katalogu zasobów
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string texPath = "/Resources/";

	// Textura cegieł
	Texture brickTex((parentDir + texPath + "brick.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);



	glfwSwapInterval(1);

	// Włączenie bufora głębokości
	glEnable(GL_DEPTH_TEST);

	// Utworzenie obiektu kamery
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));
	double lasttime = glfwGetTime();

	// Główna pętla renderowania
	while (!glfwWindowShouldClose(window))
	{
		// Ustawienie koloru tła
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Obsługa kamery
		camera.Inputs(window);
		// Aktualizacja i przekazanie macierzy kamery do Vertex Shadera
		camera.updateMatrix(45.0f, 0.1f, 100.0f);


		// Użycie Shader Programu dla obiektów renderowanych teksturą
		shaderProgram.Activate();
		// Przekazanie pozycji kamery do Fragment Shadera dla oświetlenia specularnego

		glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		// Przekazanie macierzy kamery do Vertex Shadera dla piramidy
		camera.Matrix(shaderProgram, "camMatrix");
		// Włączenie tekstury do renderowania
		brickTex.Bind();
		// Wiązanie VAO dla piramidy
		shaderProgram.setUseTexture(true);
		if (draw1)	VAO1.Bind();
		if (draw1)	glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);


		// Trójkąt 
		shaderProgram.setUseTexture(false);
		if (draw2)VAOCube.Bind();
		if (draw2)glDrawElements(GL_TRIANGLES, sizeof(cubeVertexIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		// Kula
		shaderProgram.setUseTexture(false);
		if (draw3)VAOSphere.Bind();
		if (draw3)glDrawElements(GL_TRIANGLES, sphereIndices.size(), GL_UNSIGNED_INT, 0);


		

		// Użycie Shader Programu dla światła
		lightShader.Activate();
		// Przekazanie macierzy kamery do Vertex Shadera dla sześcianu światła
		camera.Matrix(lightShader, "camMatrix");
		// Wiązanie VAO dla światła
		lightVAO.Bind();
		// Rysowanie obiektów, liczba indeksów, typ indeksów, indeksy

		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);


		// Zamiana bufora tylniego z przednim
		glfwSwapBuffers(window);
		// Obsługa wszystkich zdarzeń GLFW
		glfwPollEvents();
		// Ograniczenie ilości klatek na sekundę

		while (glfwGetTime() < lasttime + 1.0 / fps) {

		}
		lasttime += 1.0 / fps;
	}



	// Usunięcie wszystkich utworzonych obiektów
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	// Usuwanie sześcianu
	VAOCube.Delete();
	VBOCube.Delete();
	EBOCube.Delete();
	// Usuwanie trójkąta
	VAOTriangle.Delete();
	VBOTriangle.Delete();
	EBOTriangle.Delete();
	// Usuwanie kuli
	VAOSphere.Delete();
	VBOSphere.Delete();
	EBOSphere.Delete();
	brickTex.Delete();
	shaderProgram.Delete();
	lightVAO.Delete();
	lightVBO.Delete();
	lightEBO.Delete();
	lightShader.Delete();
	// Zniszczenie okna przed zakończeniem programu
	glfwDestroyWindow(window);
	// Zakończenie GLFW przed zakończeniem programu
	glfwTerminate();
}
/**
 * @brief Aktualizuje stan silnika gry.
 *
 * Funkcja odpowiedzialna za aktualizację logiki gry, stanu obiektów i innych danych w silniku.
 */
void Engine::update()
{
}
/**
 * @brief Renderuje scenę gry.
 *
 * Funkcja odpowiedzialna za renderowanie wszystkich elementów na scenie gry.
 */
void Engine::render()
{

}
/**
 * @brief Czyści zasoby i sprząta po silniku gry.
 *
 * Funkcja odpowiedzialna za zwolnienie pamięci i zasobów używanych przez silnik gry.
 */
void Engine::cleanUp()
{
}
/**
 * @brief Ustawia okno GLFW, w którym renderowany jest silnik.
 *
 * @param window Wskaźnik na okno GLFW.
 */
void Engine::setWindow(GLFWwindow* window)
{
}
/**
 * @brief Pobiera wskaźnik na okno GLFW, w którym renderowany jest silnik.
 *
 * @return Wskaźnik na okno GLFW.
 */
GLFWwindow* Engine::getWindow()
{
	return nullptr;
}
/**
 * @brief Zwraca szerokość okna.
 *
 * @return Szerokość okna w pikselach.
 */
int Engine::getWidth()
{
	return 0;
}
/**
 * @brief Zwraca wysokość okna.
 *
 * @return Wysokość okna w pikselach.
 */
int Engine::getHeight()
{
	return 0;
}
/**
 * @brief Obsługuje zdarzenia klawiatury.
 *
 * Funkcja callback obsługująca zdarzenia klawiatury przekazywane przez GLFW.
 * Zmienia stany flag `draw1`, `draw2` i `draw3` oraz ustawia liczbę klatek na sekundę (fps) przy użyciu klawiszy funkcyjnych.
 *
 * @param window Wskaźnik na okno GLFW, w którym zostało naciśnięte klawisze.
 * @param key Kod naciśniętego klawisza.
 * @param scancode Kod skanu klawisza.
 * @param action Akcja wykonana na klawiszu (np. naciśnięcie, zwolnienie).
 * @param mods Modyfikatory klawiszy (Ctrl, Shift itp.).
 */
void Engine::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
	{
		draw1 = !draw1;
	}
	if (key == GLFW_KEY_2 && action == GLFW_PRESS)
	{
		draw2 = !draw2;
	}
	if (key == GLFW_KEY_3 && action == GLFW_PRESS)
	{
		draw3 = !draw3;
	}
	//zmiana fps  f1-f4
	if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
	{
		fps = 60;
	}
	if (key == GLFW_KEY_F2 && action == GLFW_PRESS)
	{
		fps = 144;
	}
	if (key == GLFW_KEY_F3 && action == GLFW_PRESS)
	{
		fps = 5;
	}

	if (key == GLFW_KEY_F4 && action == GLFW_PRESS)
	{
		fps = 20;
	}
}