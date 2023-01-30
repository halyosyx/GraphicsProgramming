#include "Window.h"

const int WIDTH_SIZE = 800;
const int HEIGHT_SIZE = 600;
const char* PROJECT_NAME = "Project Dawn";

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Window *newWindow = new Window(WIDTH_SIZE, HEIGHT_SIZE, PROJECT_NAME);
	newWindow->RenderWindow();

	return 0;
}