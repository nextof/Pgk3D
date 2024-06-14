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
 * @brief Klasa reprezentuj¹ca silnik gry.
 *
 */
class Engine
{
private:
	
	int width;                  /**< Szerokoœæ okna. */
	int height;                 /**< Wysokoœæ okna. */
	GLFWwindow* window;         /**< WskaŸnik na okno GLFW. */

public:
	/**
	 * @brief Konstruktor klasy Engine.
	 *
	 * @param width Szerokoœæ okna.
	 * @param height Wysokoœæ okna.
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
	 * @brief Czyœci zasoby u¿ywane przez silnik gry.
	 */
	void cleanUp();
	/**
	 * @brief Ustawia wskaŸnik na okno GLFW.
	 *
	 * @param window WskaŸnik na okno GLFW.
	 */
	void setWindow(GLFWwindow* window);
	/**
	 * @brief Zwraca wskaŸnik na okno GLFW.
	 *
	 * @return GLFWwindow* WskaŸnik na okno GLFW.
	 */
	GLFWwindow* getWindow();
	/**
	 * @brief Zwraca szerokoœæ okna.
	 *
	 * @return int Szerokoœæ okna.
	 */
	int getWidth();
	/**
	* @brief Zwraca wysokoœæ okna.
	*
	* @return int Wysokoœæ okna.
	*/
	int getHeight();
	/**
	 * @brief Statyczna metoda callback dla zdarzeñ klawiatury GLFW.
	 *
	 * @param window WskaŸnik na okno GLFW, które wygenerowa³o zdarzenie.
	 * @param key Kod klawisza, który spowodowa³ zdarzenie.
	 * @param scancode Kod skanowania klawisza.
	 * @param action Akcja, która zosta³a wykonana (np. naciœniêcie, zwolnienie, powtórzenie).
	 * @param mods Bitowy stan klawiszy modyfikuj¹cych (Ctrl, Shift, Alt).
	 */
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

