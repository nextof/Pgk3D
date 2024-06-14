#pragma once


#include<filesystem>
namespace fs = std::filesystem;


#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include <thread>

#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Camera.h"


/**
 * @brief Klasa reprezentuj�ca silnik gry.
 *
 */
class Engine
{
private:
	
	int width;                  /**< Szeroko�� okna. */
	int height;                 /**< Wysoko�� okna. */
	GLFWwindow* window;         /**< Wska�nik na okno GLFW. */

public:
	/**
	 * @brief Konstruktor klasy Engine.
	 *
	 * @param width Szeroko�� okna.
	 * @param height Wysoko�� okna.
	 */
	Engine(int width, int height);
	/**
	 * @brief Destruktor klasy Engine.
	 */
	~Engine();
	/**
	 * @brief Uruchamia silnik gry.
	 */
	void run();

	/**
	 * @brief Aktualizuje stan silnika gry.
	 */
	void update();

	/**
	 * @brief Renderuje obraz na ekranie.
	 */
	void render();

	/**
	 * @brief Czy�ci zasoby u�ywane przez silnik gry.
	 */
	void cleanUp();
	/**
	 * @brief Ustawia wska�nik na okno GLFW.
	 *
	 * @param window Wska�nik na okno GLFW.
	 */
	void setWindow(GLFWwindow* window);
	/**
	 * @brief Zwraca wska�nik na okno GLFW.
	 *
	 * @return GLFWwindow* Wska�nik na okno GLFW.
	 */
	GLFWwindow* getWindow();
	/**
	 * @brief Zwraca szeroko�� okna.
	 *
	 * @return int Szeroko�� okna.
	 */
	int getWidth();
	/**
	* @brief Zwraca wysoko�� okna.
	*
	* @return int Wysoko�� okna.
	*/
	int getHeight();
	/**
	 * @brief Statyczna metoda callback dla zdarze� klawiatury GLFW.
	 *
	 * @param window Wska�nik na okno GLFW, kt�re wygenerowa�o zdarzenie.
	 * @param key Kod klawisza, kt�ry spowodowa� zdarzenie.
	 * @param scancode Kod skanowania klawisza.
	 * @param action Akcja, kt�ra zosta�a wykonana (np. naci�ni�cie, zwolnienie, powt�rzenie).
	 * @param mods Bitowy stan klawiszy modyfikuj�cych (Ctrl, Shift, Alt).
	 */
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

