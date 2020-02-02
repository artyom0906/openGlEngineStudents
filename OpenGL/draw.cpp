#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../shaders/Shader.h"
#include "figures/square.hpp"
GLFWwindow* window;
unsigned int SCR_WIDTH, SCR_HEIGHT;

int InitApp()
{
	// glfw: initialize and configure
	// ------------------------------
	#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for OSX
	#endif
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	SCR_WIDTH = 800;
	SCR_HEIGHT = 600;
	// glfw window creation
	// --------------------
	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	return 0;
}

int Rendering(DrawTriangles& tr, DrawSquare& sq)
{
	Shader shader("shaders/Vertex.vs", "shaders/Pixel.ps");
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.9f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		shader.use();
		tr.useBuffers();
		sq.useBuffers();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	tr.deleteBuffers();
	sq.deleteBuffers();
	glfwTerminate();
	return 0;
}