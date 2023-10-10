#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main()
{

	if (!glfwInit())
	{

	}



	GLFWwindow* window = glfwCreateWindow(640, 480, "Titulo", NULL, NULL);
	if (!window)
	{

	}

	
	glfwMakeContextCurrent(window);
	int width{};
	int height{};
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glfwSetKeyCallback(window, key_callback);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "error\n";
	}

	std::cout << glGetString(GL_VERSION);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);

		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);

		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}