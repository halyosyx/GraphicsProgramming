#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>

void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height);
void RenderWindow(GLFWwindow* window);
void Inputs(GLFWwindow* window);

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGLProject", NULL, NULL);

	if (window == NULL)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, Framebuffer_Size_Callback);
	
	RenderWindow(window);

	return 0;
}

void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void RenderWindow(GLFWwindow* window)
{
	while (!glfwWindowShouldClose(window))
	{
		Inputs(window);

		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}

//Rework Inputs and place them in seperate class
void Inputs(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		std::cout << "PRESSED ESCAPE KEY" << std::endl;
		glfwSetWindowShouldClose(window, true);
	}
}