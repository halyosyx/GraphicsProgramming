#include "Window.h"
#include "Input.h"

Window::Window(int width, int height, const char *name)
{
	window = glfwCreateWindow(width, height, name, NULL, NULL);
}

void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Window::RenderWindow()
{
	if (window == NULL)
	{
		std::cout << "CONSTRUCTOR FAIL!!!" << std::endl;
		std::cout << "WINDOW DOES NOT EXIST!" << std::endl;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, Framebuffer_Size_Callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return;

	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			std::cout << "PRESSED ESCAPE KEY" << std::endl;
			glfwSetWindowShouldClose(window, true);
		}

		//Background
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}



GLFWwindow* Window::GetWindow()
{
	return window;
}

Window::~Window()
{
}
