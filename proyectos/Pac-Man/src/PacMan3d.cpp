#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Application.h"

Application app;

//Se ejecuta cuando la ventana cambia de tamaño. Parámetros en pixeles.
//(ojo: En otros programas se debe ejecutar glViewport)


void reshape(int w, int h)
{
	app.reshape(w, h);
}


void keyboard(GLFWwindow* window, int key, int scancode, int actions, int mods)
{
	app.keyboard(key, scancode, actions, mods);
}

int main(int argc, char *argv[])
{

	/* Initialize the library */
	if (!glfwInit())
		return -1;
	//glfwWindowHint(GLFW_ALPHA_BITS, GLFW_TRUE);
	/* Create a windowed mode window and its OpenGL context */
	app.window = glfwCreateWindow(1500, 1500, "Hello Cube", NULL, NULL);
	if (!app.window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(app.window);

	glewExperimental = GL_TRUE;
	glewInit();
	app.setup();

	// get version info 
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf(" Renderer: %s\n", renderer);
	printf(" OpenGL version supported %s\n", version);

	// tell GL to only draw onto a pixel if the shape is closer to the viewer 
	glEnable(GL_DEPTH_TEST); // enable depth-testing 	
	glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer" 

	glfwSetKeyCallback(app.window, keyboard);

	while (!glfwWindowShouldClose(app.window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glDepthRange(0.1,1.0);

		/* update other events like input handling */
		glfwPollEvents();
		app.update();
		glDepthRange(0.1f, 10.0f);
		/* put the stuff we've been drawing onto the display */
		glViewport(0, 0, (GLsizei)1500, (GLsizei)1500);
		app.display();
		glDepthRange(0.f, 0.1f);
		glViewport(0, 0, (GLsizei)1500 /4, (GLsizei)1500/4);
		app.display2();

		glfwSwapBuffers(app.window);
	}

	/* close GL context and any other GLFW resources */
	glfwTerminate();
	return 0;

}