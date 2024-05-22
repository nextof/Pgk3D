#include "Engine.h"



// Sześcian
GLfloat cubeArray[] = {
	// front
	-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,            // 0
	0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,             // 1
	0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,              // 2
	-0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,             // 3

	// top								   
	-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,            // 4
	0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,             // 5
	0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,              // 6
	-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,             // 7

	// left								   
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,            // 8
	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,             // 9
	-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,              // 10
	-0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f,             // 11

	// right							   
	0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f,            // 12
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,             // 13
	0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f,              // 14
	0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 0.0f,             // 15

	// back								   
	-0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 1.0f,            // 16
	0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 1.0f,             // 17
	0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f,              // 18
	-0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f,             // 19

	// bottom							   
	-0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 1.0f,            // 20
	0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 1.0f,             // 21
	0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f,            // 22
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f,           // 23
};

GLuint cubeVertexIndices[] = {
	// front
	0, 1, 2, // first triangle
	2, 3, 0, // second triangle

	// top
	4, 5, 6, // first triangle
	6, 7, 4, // second triangle

	// left
	8, 9, 10,  // first triangle
	10, 11, 8, // second triangle

	// right
	14, 13, 12, // 12, 13, 14, // first triangle
	12, 15, 14, // 14, 15, 12, // second triangle

	// back
	18, 17, 16, // 16, 17, 18, // first triangle
	16, 19, 18, // 18, 19, 16, // second triangle

	// bottom
	20, 21, 22, // first triangle
	22, 23, 20  // second triangle
};

// Wierzchołki trójkąta
GLfloat triangleVertices[] = {
	//     COORDINATES              /        COLORS          /    TexCoord   /        NORMALS       
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


// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS          /    TexCoord   /        NORMALS       //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side

	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,     -0.8f, 0.5f,  0.0f, // Left Side

	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f, -0.8f, // Non-facing side

	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.8f, 0.5f,  0.0f, // Right side

	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f,  0.8f  // Facing side
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2, // Bottom side
	0, 2, 3, // Bottom side
	4, 6, 5, // Left side
	7, 9, 8, // Non-facing side
	10, 12, 11, // Right side
	13, 15, 14 // Facing side
};

GLfloat lightVertices[] =
{ //     COORDINATES     //
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
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);
}

Engine::~Engine()
{
	// Usuwanie okna przed zakończeniem programu
	glfwDestroyWindow(window);
	// Wyłączenie GLFW przed zakończeniem programu
	glfwTerminate();
}

void Engine::run()
{
	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
	Shader shaderProgram2("default.vert", "default.frag");


	//Tworzenie trójkąta
	VAO VAOTriangle;
	VAOTriangle.Bind();

	VBO VBOTriangle(triangleVertices, sizeof(triangleVertices));
	EBO EBOTriangle(triangleIndices, sizeof(triangleIndices));

	VAOTriangle.LinkAttrib(VBOTriangle, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAOTriangle.LinkAttrib(VBOTriangle, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAOTriangle.LinkAttrib(VBOTriangle, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAOTriangle.LinkAttrib(VBOTriangle, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

	VAOTriangle.Unbind();
	VBOTriangle.Unbind();
	EBOTriangle.Unbind();



	// Generates Vertex Array Object and binds it
	VAO VAOCube;
	VAOCube.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	//VBO VBO1(vertices, sizeof(vertices));

	VBO VBOCube(cubeArray, sizeof(cubeArray));

	// Generates Element Buffer Object and links it to indices
	//EBO EBO1(indices, sizeof(indices));

	EBO EBOCube(cubeVertexIndices, sizeof(cubeVertexIndices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAOCube.LinkAttrib(VBOCube, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAOCube.LinkAttrib(VBOCube, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	VAOCube.LinkAttrib(VBOCube, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAOCube.LinkAttrib(VBOCube, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAOCube.Unbind();
	VBOCube.Unbind();
	EBOCube.Unbind();


	// Shader for light cube
	Shader lightShader("light.vert", "light.frag");
	// Generates Vertex Array Object and binds it
	VAO lightVAO;
	lightVAO.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	VBO lightVBO(lightVertices, sizeof(lightVertices));
	// Generates Element Buffer Object and links it to indices
	EBO lightEBO(lightIndices, sizeof(lightIndices));
	// Links VBO attributes such as coordinates and colors to VAO
	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	// Unbind all to prevent accidentally modifying them
	lightVAO.Unbind();
	lightVBO.Unbind();
	lightEBO.Unbind();



	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 pyramidModel = glm::mat4(1.0f);
	pyramidModel = glm::translate(pyramidModel, pyramidPos);

	// Aktualizacja macierzy modelu dla trójkąta
	glm::vec3 trianglePos = glm::vec3(3.0f, 0.0f, 0.0f);
	glm::mat4 triangleModel = glm::mat4(1.0f);
	triangleModel = glm::translate(triangleModel, trianglePos);


	//lightShader.Activate();
	//glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	//glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	shaderProgram2.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram2.ID, "model"), 1, GL_FALSE, glm::value_ptr(triangleModel));
	//glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
//	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);



	/*
	* I'm doing this relative path thing in order to centralize all the resources into one folder and not
	* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
	* folder and then give a relative path from this folder to whatever resource you want to get to.
	* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
	*/
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string texPath = "/Resources/YoutubeOpenGL 7 - Going 3D/";

	// Texture
	Texture brickTex((parentDir + texPath + "brick.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	//brickTex.texUnit(shaderProgram, "tex0", 0);

	// Original code from the tutorial
	/*Texture brickTex("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);*/


	glfwSwapInterval(1);

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);


		// Tells OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		shaderProgram2.Activate();
		// Exports the camera Position to the Fragment Shader for specular lighting
		glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		// Export the camMatrix to the Vertex Shader of the pyramid
		camera.Matrix(shaderProgram, "camMatrix");
		// Binds texture so that is appears in rendering
		//brickTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAOCube.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		//glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

		glDrawElements(GL_TRIANGLES, sizeof(cubeVertexIndices) / sizeof(int), GL_UNSIGNED_INT, 0);


		// Trójkąt 
		VAOTriangle.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(triangleIndices) / sizeof(int), GL_UNSIGNED_INT, 0);


		// Tells OpenGL which Shader Program we want to use
		//lightShader.Activate();
		// Export the camMatrix to the Vertex Shader of the light cube
		//camera.Matrix(lightShader, "camMatrix");
		// Bind the VAO so OpenGL knows to use it
		//lightVAO.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		//glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);


		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	// Usuwanie sześcianu
	VAOCube.Delete();
	VBOCube.Delete();
	EBOCube.Delete();
	// Usuwanie trójkąta
	VAOTriangle.Delete();
	VBOTriangle.Delete();
	EBOTriangle.Delete();
	brickTex.Delete();
	shaderProgram.Delete();
	lightVAO.Delete();
	lightVBO.Delete();
	lightEBO.Delete();
	lightShader.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
}

void Engine::update()
{
}

void Engine::render()
{

}

void Engine::cleanUp()
{
}

void Engine::setWindow(GLFWwindow* window)
{
}

GLFWwindow* Engine::getWindow()
{
	return nullptr;
}

int Engine::getWidth()
{
	return 0;
}

int Engine::getHeight()
{
	return 0;
}
#include "Engine.h"



// Sześcian
GLfloat cubeArray[] = {
	// front
	-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,            // 0
	0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,             // 1
	0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,              // 2
	-0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,             // 3

	// top								   
	-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,            // 4
	0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,             // 5
	0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,              // 6
	-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,             // 7

	// left								   
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,            // 8
	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,             // 9
	-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,              // 10
	-0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f,             // 11

	// right							   
	0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f,            // 12
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,             // 13
	0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f,              // 14
	0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 0.0f,             // 15

	// back								   
	-0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 1.0f,            // 16
	0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 1.0f,             // 17
	0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f,              // 18
	-0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f,             // 19

	// bottom							   
	-0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 1.0f,            // 20
	0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 1.0f,             // 21
	0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f,            // 22
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f,           // 23
};

GLuint cubeVertexIndices[] = {
	// front
	0, 1, 2, // first triangle
	2, 3, 0, // second triangle

	// top
	4, 5, 6, // first triangle
	6, 7, 4, // second triangle

	// left
	8, 9, 10,  // first triangle
	10, 11, 8, // second triangle

	// right
	14, 13, 12, // 12, 13, 14, // first triangle
	12, 15, 14, // 14, 15, 12, // second triangle

	// back
	18, 17, 16, // 16, 17, 18, // first triangle
	16, 19, 18, // 18, 19, 16, // second triangle

	// bottom
	20, 21, 22, // first triangle
	22, 23, 20  // second triangle
};

// Wierzchołki trójkąta
GLfloat triangleVertices[] = {
	//     COORDINATES              /        COLORS          /    TexCoord   /        NORMALS       
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


// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS          /    TexCoord   /        NORMALS       //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side

	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,     -0.8f, 0.5f,  0.0f, // Left Side

	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f, -0.8f, // Non-facing side

	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.8f, 0.5f,  0.0f, // Right side

	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f,  0.8f  // Facing side
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2, // Bottom side
	0, 2, 3, // Bottom side
	4, 6, 5, // Left side
	7, 9, 8, // Non-facing side
	10, 12, 11, // Right side
	13, 15, 14 // Facing side
};

GLfloat lightVertices[] =
{ //     COORDINATES     //
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
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);
}

Engine::~Engine()
{
	// Usuwanie okna przed zakończeniem programu
	glfwDestroyWindow(window);
	// Wyłączenie GLFW przed zakończeniem programu
	glfwTerminate();
}

void Engine::run()
{
	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
	Shader shaderProgram2("default.vert", "default.frag");


	//Tworzenie trójkąta
	VAO VAOTriangle;
	VAOTriangle.Bind();

	VBO VBOTriangle(triangleVertices, sizeof(triangleVertices));
	EBO EBOTriangle(triangleIndices, sizeof(triangleIndices));

	VAOTriangle.LinkAttrib(VBOTriangle, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAOTriangle.LinkAttrib(VBOTriangle, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAOTriangle.LinkAttrib(VBOTriangle, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAOTriangle.LinkAttrib(VBOTriangle, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

	VAOTriangle.Unbind();
	VBOTriangle.Unbind();
	EBOTriangle.Unbind();



	// Generates Vertex Array Object and binds it
	VAO VAOCube;
	VAOCube.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	//VBO VBO1(vertices, sizeof(vertices));

	VBO VBOCube(cubeArray, sizeof(cubeArray));

	// Generates Element Buffer Object and links it to indices
	//EBO EBO1(indices, sizeof(indices));

	EBO EBOCube(cubeVertexIndices, sizeof(cubeVertexIndices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAOCube.LinkAttrib(VBOCube, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAOCube.LinkAttrib(VBOCube, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	VAOCube.LinkAttrib(VBOCube, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAOCube.LinkAttrib(VBOCube, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAOCube.Unbind();
	VBOCube.Unbind();
	EBOCube.Unbind();


	// Shader for light cube
	Shader lightShader("light.vert", "light.frag");
	// Generates Vertex Array Object and binds it
	VAO lightVAO;
	lightVAO.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	VBO lightVBO(lightVertices, sizeof(lightVertices));
	// Generates Element Buffer Object and links it to indices
	EBO lightEBO(lightIndices, sizeof(lightIndices));
	// Links VBO attributes such as coordinates and colors to VAO
	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	// Unbind all to prevent accidentally modifying them
	lightVAO.Unbind();
	lightVBO.Unbind();
	lightEBO.Unbind();



	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 pyramidModel = glm::mat4(1.0f);
	pyramidModel = glm::translate(pyramidModel, pyramidPos);

	// Aktualizacja macierzy modelu dla trójkąta
	glm::vec3 trianglePos = glm::vec3(3.0f, 0.0f, 0.0f);
	glm::mat4 triangleModel = glm::mat4(1.0f);
	triangleModel = glm::translate(triangleModel, trianglePos);


	//lightShader.Activate();
	//glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	//glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	shaderProgram2.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram2.ID, "model"), 1, GL_FALSE, glm::value_ptr(triangleModel));
	//glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
//	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);



	/*
	* I'm doing this relative path thing in order to centralize all the resources into one folder and not
	* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
	* folder and then give a relative path from this folder to whatever resource you want to get to.
	* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
	*/
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string texPath = "/Resources/YoutubeOpenGL 7 - Going 3D/";

	// Texture
	Texture brickTex((parentDir + texPath + "brick.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	//brickTex.texUnit(shaderProgram, "tex0", 0);

	// Original code from the tutorial
	/*Texture brickTex("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);*/


	glfwSwapInterval(1);

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);


		// Tells OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		shaderProgram2.Activate();
		// Exports the camera Position to the Fragment Shader for specular lighting
		glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		// Export the camMatrix to the Vertex Shader of the pyramid
		camera.Matrix(shaderProgram, "camMatrix");
		// Binds texture so that is appears in rendering
		//brickTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAOCube.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		//glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

		glDrawElements(GL_TRIANGLES, sizeof(cubeVertexIndices) / sizeof(int), GL_UNSIGNED_INT, 0);


		// Trójkąt 
		VAOTriangle.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(triangleIndices) / sizeof(int), GL_UNSIGNED_INT, 0);


		// Tells OpenGL which Shader Program we want to use
		//lightShader.Activate();
		// Export the camMatrix to the Vertex Shader of the light cube
		//camera.Matrix(lightShader, "camMatrix");
		// Bind the VAO so OpenGL knows to use it
		//lightVAO.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		//glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);


		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	// Usuwanie sześcianu
	VAOCube.Delete();
	VBOCube.Delete();
	EBOCube.Delete();
	// Usuwanie trójkąta
	VAOTriangle.Delete();
	VBOTriangle.Delete();
	EBOTriangle.Delete();
	brickTex.Delete();
	shaderProgram.Delete();
	lightVAO.Delete();
	lightVBO.Delete();
	lightEBO.Delete();
	lightShader.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
}

void Engine::update()
{
}

void Engine::render()
{

}

void Engine::cleanUp()
{
}

void Engine::setWindow(GLFWwindow* window)
{
}

GLFWwindow* Engine::getWindow()
{
	return nullptr;
}

int Engine::getWidth()
{
	return 0;
}

int Engine::getHeight()
{
	return 0;
}
