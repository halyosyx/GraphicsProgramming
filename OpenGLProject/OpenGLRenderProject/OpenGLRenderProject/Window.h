#pragma once
#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include <string>

//Decide if I need to make this into a singleton

class Window
{
public:

	Window(int width,int height, const char *name);
	void RenderWindow();
	GLFWwindow* GetWindow();
	~Window();

private:
	GLFWwindow* window;

};

