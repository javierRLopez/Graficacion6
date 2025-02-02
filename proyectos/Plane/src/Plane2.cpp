#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Application.h"

Application app;

//Se tiene que llamar despues de inicializar la ventana y el OpenGL, pero antes del main loop
void setup() {
	app.setup();
}

//Se ejecuta siempre que se necesite actualizar la imagen
void display() {
	app.display();
}

//Se ejecuta cuando la ventana cambia de tama�o. Par�metros en pixeles.
//(ojo: En otros programas se debe ejecutar glViewport)
void reshape(int w, int h) {
	app.reshape(w, h);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	app.keyboard(key, scancode, action, mods);
}

void cursor_position(GLFWwindow* window, double xpos, double ypos)
{
	app.mouse(xpos, ypos);
}

int main(int argc, char *argv[]) {

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1024, 768, "Hello Plane", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();
	app.setup();

	// get version info 
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf(" Renderer: %s\ n", renderer);
	printf(" OpenGL version supported %s\ n", version);

	// tell GL to only draw onto a pixel if the shape is closer to the viewer 
	//glEnable (GL_DEPTH_TEST); // enable depth-testing 	
	//glDepthFunc (GL_LESS); // depth-testing interprets a smaller value as "closer" 

	glViewport(0, 0, (GLsizei)1024, (GLsizei)768);
	glEnable(GL_DEPTH_TEST); //Z-buffer

	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_position);

	while (!glfwWindowShouldClose(window))
	{
		/* update other events like input handling */
		glfwPollEvents();

		app.update();
		/* put the stuff we've been drawing onto the display */
		app.display();

		glfwSwapBuffers(window);
	}

	/* close GL context and any other GLFW resources */
	glfwTerminate();
	return 0;

}