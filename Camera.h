#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include"shaderClass.h"

class Camera
{
public:
	// Przechowuje g��wne wektory kamery
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	// Zapobiega skokom kamery przy pierwszym klikni�ciu lewego przycisku myszy
	bool firstClick = true;

	// Przechowuje szeroko�� i wysoko�� okna
	int width;
	int height;

	// Dostosowuje pr�dko�� kamery oraz jej czu�o�� podczas obracania
	float speed = 0.01f;
	float sensitivity = 100.0f;

	// Konstruktor kamery do ustawienia warto�ci pocz�tkowych
	Camera(int width, int height, glm::vec3 position);

	// Aktualizuje macierz kamery do Vertex Shadera
	void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
	// Eksportuje macierz kamery do shadera
	void Matrix(Shader& shader, const char* uniform);
	// Obs�uguje wej�cia kamery
	void Inputs(GLFWwindow* window);
};
#endif