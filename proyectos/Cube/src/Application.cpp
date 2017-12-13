#include "Application.h"
#include <iostream>
#include <vector>

#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


#include "ShaderFuncs.h"

GLfloat vertexPositions[] = {
	//Quad1
	-1.0f, 1.0f, -1.0f, 1.0f, //h
	 1.0f, -1.0f, -1.0f, 1.0f, //n
	 1.0f, 1.0f,	-1.0f, 1.0f, //g
	-1.0f, 1.0f, -1.0f, 1.0f, //h
	 1.0f, -1.0f, -1.0f, 1.0f, //n
	-1.0f, -1.0f, -1.0f, 1.0f, //m

							   
    -1.0f, 1.0f, -1.0f, 1.0f, //h
	 1.0f, 1.0f,	-1.0f, 1.0f, //g
	-1.0f, 1.0f, 1.0f, 1.0f, //d
	 1.0f, 1.0f,	-1.0f, 1.0f, //g
	-1.0f, 1.0f, 1.0f, 1.0f, //d
	 1.0f, 1.0f, 1.0f, 1.0f, //c						   

	 -1.0f, 1.0f, 1.0f, 1.0f, //d
	 1.0f, 1.0f, 1.0f, 1.0f, //c
	 -1.0f, -1.0f, 1.0, 1.0, //a
	 1.0f, 1.0f, 1.0f, 1.0f, //c
	 -1.0f, -1.0f, 1.0, 1.0, //a
	 1.0f, -1.0f, 1.0f, 1.0f, //b												   //Quad3
													   
	 1.0f, 1.0f, 1.0f, 1.0f, //c
	 1.0f, -1.0f, 1.0f, 1.0f, //b
	 1.0f, 1.0f, -1.0f, 1.0f, //i
	 1.0f, -1.0f, 1.0f, 1.0f, //b
	 1.0f, 1.0f, -1.0f, 1.0f, //i
	 1.0f, -1.0f, -1.0f, 1.0f, //j

	 -1.0f, 1.0f, 1.0f, 1.0f, //d
	 -1.0f, -1.0f, 1.0, 1.0, //a
	 -1.0f, 1.0f, -1.0f, 1.0f, //h
	 -1.0f, -1.0f, 1.0, 1.0, //a
	 -1.0f, 1.0f, -1.0f, 1.0f, //h
	 -1.0f, -1.0f, -1.0f, 1.0f, //m

												

	 1.0f, -1.0f, 1.0f, 1.0f, //b
	 -1.0f, -1.0f, 1.0, 1.0, //a
	 -1.0f, -1.0f, -1.0f, 1.0f, //m
	 1.0f, -1.0f, 1.0f, 1.0f, //b
	 -1.0f, -1.0f, -1.0f, 1.0f, //m
	 1.0f, -1.0f, -1.0f, 1.0f, //n
																										  
};


GLfloat vertexColors[] = {
	
	1.0f, 0.0f, 0.0f, 0.5f,
	1.0f, 0.0f, 0.0f, 0.5f,
	1.0f, 1.0f, 0.0f, 0.5f,
	1.0f, 0.0f, 1.0f, 0.5f,
	1.0f, 0.0f, 0.0f, 0.5f,
	1.0f, 0.0f, 0.0f, 0.5f,


	1.0f, 1.0f, 0.0f, 0.5f,
	2.0f, 1.0f, 0.0f, 0.5f,
	3.0f, 1.0f, 0.0f, 0.5f,
	0.0f, 1.0f, 0.0f, 0.5f,
	6.0f, 1.0f, 0.0f, 0.5f,
	0.0f, 1.0f, 0.0f, 0.5f,


	1.0f, 0.0f, 1.0f, 0.5f,
	0.0f, 0.0f, 1.0f, 0.5f,
	1.0f, 0.0f, 1.0f, 0.5f,
	0.0f, 0.0f, 1.0f, 0.5f,
	1.0f, 0.0f, 1.0f, 0.5f,
	0.0f, 0.0f, 1.0f, 0.5f,


	1.0f, 1.0f, 1.1f, 1.0f,
	1.0f, 1.0f, 1.1f, 1.0f,
	1.0f, 1.0f, 1.1f, 1.0f,
	1.0f, 1.0f, 1.1f, 1.0f,
	1.0f, 1.0f, 1.1f, 1.0f,
	1.0f, 1.0f, 1.1f, 1.0f,


	1.0f, 1.0f, 0.0f, 0.0f,
	1.0f, 1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f, 0.0f,
	1.0f, 1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f, 0.0f,
	1.0f, 1.0f, 0.0f, 0.0f,

	
	1.0f, 1.65f, 0.0f, 0.0f,
	1.0f, 0.65f, 0.0f, 0.0f,
	1.0f, 1.65f, 0.0f, 0.0f,
	1.0f, 1.65f, 0.0f, 0.0f,
	1.0f, 1.65f, 0.0f, 0.0f,
	1.0f, 0.65f, 0.0f, 0.0f,
};


Application::Application() : eye(2.0f, 0.0f, 5.0f),
target(0.0f, 0.0f, 0.0f),
transform(glm::mat4(1.0f)),
angles(1.0f, 0.0f, 0.0f)
{}

Application::~Application()
{}

void Application::update()
{
	angles.y++;
	angles.x += 5.0f;
	camera = glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f));
	transform = glm::rotate(glm::mat4(1.0f), glm::radians(angles.x), glm::vec3(1.0f, 0.0f, 0.0f));
	transform = glm::rotate(transform, glm::radians(angles.y), glm::vec3(0.0f, 1.0f, 0.0f));
	transform = glm::perspective(45.0f, 1.35f, 0.1f, 10.0f) *
		camera * transform;
}

void Application::keyboard(int key, int scancode, int actions, int mods)
{
	if (actions == GLFW_RELEASE)
	{
		switch (key)
		{
		case GLFW_KEY_ESCAPE: glfwSetWindowShouldClose(window, GLFW_TRUE);
			break;

		case GLFW_KEY_W:
			
			break;

		case GLFW_KEY_S:
			break;
		}
	}
	
}

void Application::setup()
{
	std::string strVertexShader = loadTextFile("Shaders\\vertex.vs");
	std::string strFragmentShader = loadTextFile("Shaders\\fragment.fs");

	InitializeProgram(cube.shader, strVertexShader, strFragmentShader);
	idTransform = glGetUniformLocation(cube.shader, "transform");

	cube.numVertex = 36;
	glGenVertexArrays(1, &cube.vao);
	glBindVertexArray(cube.vao);
	glGenBuffers(1, &cube.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, cube.vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions) + sizeof(vertexColors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, sizeof(vertexPositions), vertexPositions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexPositions), sizeof(vertexColors), vertexColors);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(vertexPositions));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

}


void Application::display()
{
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Seleccionamos los shaders a usar
	glUseProgram(cube.shader);
	glUniformMatrix4fv(idTransform, 1, GL_FALSE, glm::value_ptr(transform));

	//activamos el vertex array object y dibujamos
	glBindVertexArray(cube.vao);

	glDrawArrays(GL_TRIANGLES, 0, cube.numVertex);
}

void Application::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}