#pragma once

//------- Ignore this ----------
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------

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

class Engine
{
private:
	
	int width;
	int height;
	GLFWwindow* window;




public:
	Engine(int width, int height);
	~Engine();
	void run();
	void update();
	void render();
	void cleanUp();
	void setWindow(GLFWwindow* window);
	GLFWwindow* getWindow();
	int getWidth();
	int getHeight();

};

