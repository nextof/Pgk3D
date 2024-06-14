#include"Camera.h"


/**
 * @brief Konstruktor kamery inicjuj�cy jej parametry pocz�tkowe.
 *
 * @param width Szeroko�� okna.
 * @param height Wysoko�� okna.
 * @param position Pocz�tkowa pozycja kamery.
 */
Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Position = position;
}
/**
 * @brief Aktualizuje macierz kamery na podstawie podanych parametr�w.
 *
 * @param FOVdeg Pole widzenia kamery w stopniach.
 * @param nearPlane Odleg�o�� do p�aszczyzny przyci�cia bliskiego.
 * @param farPlane Odleg�o�� do p�aszczyzny przyci�cia dalekiego.
 */
void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	// Inicjalizuje macierze, poniewa� w przeciwnym razie b�d� to puste macierze
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	// Ustawia kamer� w odpowiednim kierunku z odpowiedniej pozycji
	view = glm::lookAt(Position, Position + Orientation, Up);
	// Dodaje perspektyw� do sceny
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	// Ustawia now� macierz kamery
	cameraMatrix = projection * view;
}
/**
 * @brief Eksportuje macierz kamery do podanego shadera.
 *
 * @param shader Referencja do obiektu shadera, do kt�rego b�dzie eksportowana macierz.
 * @param uniform Nazwa zmiennej uniform w shaderze, do kt�rej ma by� przypisana macierz.
 */
void Camera::Matrix(Shader& shader, const char* uniform)
{
	// Eksportuje macierz kamery
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

/**
 * @brief Obs�uguje wej�cia u�ytkownika dla kamery, takie jak poruszanie si� i obracanie.
 *
 * @param window Okno GLFW, z kt�rego pobierane s� dane o wej�ciach.
 */
void Camera::Inputs(GLFWwindow* window)
{
	// Obs�uguje wej�cia klawiatury
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



	// Obs�uguje wej�cia myszy
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		// Ukrywa kursor myszy
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		// Zapobiega skokom kamery przy pierwszym klikni�ciu
		if (firstClick)
		{
			glfwSetCursorPos(window, (width / 2), (height / 2));
			firstClick = false;
		}

		// Pobiera wsp�rz�dne kursora
		double mouseX;
		double mouseY;
		// Normalizuje i przesuwa wsp�rz�dne kursora, tak aby rozpoczyna�y si� w �rodku ekranu,
		// a nast�pnie "transformuje" je na stopnie
		glfwGetCursorPos(window, &mouseX, &mouseY);

		// Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
		// and then "transforms" them into degrees 
		float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
		float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

		// Oblicza przysz�� zmian� orientacji pionowej
		glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));

		// Decyduje, czy nast�pna orientacja pionowa jest legalna czy nie
		if (abs(glm::angle(newOrientation, Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			Orientation = newOrientation;
		}

		// Obraca orientacj� w lewo i w prawo
		Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);

		// Ustawia kursor myszy na �rodku ekranu, aby nie m�g� si� swobodnie porusza�
		glfwSetCursorPos(window, (width / 2), (height / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		// Pokazuje kursor, poniewa� kamera nie obraca si� ju�
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		// Zapewnia, �e nast�pnym razem kamera nie skoczy
		firstClick = true;
	}
}