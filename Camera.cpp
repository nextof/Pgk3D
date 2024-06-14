#include"Camera.h"


/**
 * @brief Konstruktor kamery inicjuj¹cy jej parametry pocz¹tkowe.
 *
 * @param width Szerokoœæ okna.
 * @param height Wysokoœæ okna.
 * @param position Pocz¹tkowa pozycja kamery.
 */
Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Position = position;
}
/**
 * @brief Aktualizuje macierz kamery na podstawie podanych parametrów.
 *
 * @param FOVdeg Pole widzenia kamery w stopniach.
 * @param nearPlane Odleg³oœæ do p³aszczyzny przyciêcia bliskiego.
 * @param farPlane Odleg³oœæ do p³aszczyzny przyciêcia dalekiego.
 */
void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	// Inicjalizuje macierze, poniewa¿ w przeciwnym razie bêd¹ to puste macierze
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	// Ustawia kamerê w odpowiednim kierunku z odpowiedniej pozycji
	view = glm::lookAt(Position, Position + Orientation, Up);
	// Dodaje perspektywê do sceny
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	// Ustawia now¹ macierz kamery
	cameraMatrix = projection * view;
}
/**
 * @brief Eksportuje macierz kamery do podanego shadera.
 *
 * @param shader Referencja do obiektu shadera, do którego bêdzie eksportowana macierz.
 * @param uniform Nazwa zmiennej uniform w shaderze, do której ma byæ przypisana macierz.
 */
void Camera::Matrix(Shader& shader, const char* uniform)
{
	// Eksportuje macierz kamery
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

/**
 * @brief Obs³uguje wejœcia u¿ytkownika dla kamery, takie jak poruszanie siê i obracanie.
 *
 * @param window Okno GLFW, z którego pobierane s¹ dane o wejœciach.
 */
void Camera::Inputs(GLFWwindow* window)
{
	// Obs³uguje wejœcia klawiatury
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Position += speed * Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		Position += speed * -glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Position += speed * -Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		Position += speed * glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		Position += speed * Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		Position += speed * -Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		speed = 0.4f;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
	{
		speed = 0.1f;
	}



	// Obs³uguje wejœcia myszy
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		// Ukrywa kursor myszy
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		// Zapobiega skokom kamery przy pierwszym klikniêciu
		if (firstClick)
		{
			glfwSetCursorPos(window, (width / 2), (height / 2));
			firstClick = false;
		}

		// Pobiera wspó³rzêdne kursora
		double mouseX;
		double mouseY;
		// Normalizuje i przesuwa wspó³rzêdne kursora, tak aby rozpoczyna³y siê w œrodku ekranu,
		// a nastêpnie "transformuje" je na stopnie
		glfwGetCursorPos(window, &mouseX, &mouseY);

		// Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
		// and then "transforms" them into degrees 
		float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
		float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

		// Oblicza przysz³¹ zmianê orientacji pionowej
		glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));

		// Decyduje, czy nastêpna orientacja pionowa jest legalna czy nie
		if (abs(glm::angle(newOrientation, Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			Orientation = newOrientation;
		}

		// Obraca orientacjê w lewo i w prawo
		Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);

		// Ustawia kursor myszy na œrodku ekranu, aby nie móg³ siê swobodnie poruszaæ
		glfwSetCursorPos(window, (width / 2), (height / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		// Pokazuje kursor, poniewa¿ kamera nie obraca siê ju¿
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		// Zapewnia, ¿e nastêpnym razem kamera nie skoczy
		firstClick = true;
	}
}