#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "ShaderFuncs.h"


#include "Application.h"
#include <iostream>
#include <vector>

GLfloat vertexPositions[] = {
	//Quad1
	-1.0f, 1.0f, -1.0f, 1.0f, //h
	1.0f, -1.0f, -1.0f, 1.0f, //n
	1.0f, 1.0f,	-1.0f, 1.0f, //g
	-1.0f, 1.0f, -1.0f, 1.0f, //h
	1.0f, -1.0f, -1.0f, 1.0f, //n
	-1.0f, -1.0f, -1.0f, 1.0f,


	//Quad2
	-1.0f, 1.0f, -1.0f, 1.0f, //h
	1.0f, 1.0f,	-1.0f, 1.0f, //g
	-1.0f, 1.0f, 1.0f, 1.0f, //d
	1.0f, 1.0f,	-1.0f, 1.0f, //g
	-1.0f, 1.0f, 1.0f, 1.0f, //d
	1.0f, 1.0f, 1.0f, 1.0f, 

	//Quad3
	-1.0f, 1.0f, 1.0f, 1.0f, //d
	 1.0f, 1.0f, 1.0f, 1.0f, //c
	-1.0f, -1.0f, 1.0, 1.0, //a
	 1.0f, 1.0f, 1.0f, 1.0f, //c
	-1.0f, -1.0f, 1.0, 1.0, //a
	 1.0f, -1.0f, 1.0f, 1.0f, 

	//Quad4
	1.0f, 1.0f, 1.0f, 1.0f, //c
	1.0f, -1.0f, 1.0f, 1.0f, //b
	1.0f, 1.0f, -1.0f, 1.0f, //i
	1.0f, -1.0f, 1.0f, 1.0f, //b
	1.0f, 1.0f, -1.0f, 1.0f, //i
	1.0f, -1.0f, -1.0f, 1.0f, 

	//Quad5
	-1.0f, 1.0f, 1.0f, 1.0f, //d
	-1.0f, -1.0f, 1.0, 1.0, //a
	-1.0f, 1.0f, -1.0f, 1.0f, //h
	-1.0f, -1.0f, 1.0, 1.0, //a
	-1.0f, 1.0f, -1.0f, 1.0f, //h
	-1.0f, -1.0f, -1.0f, 1.0f, 

	//Quad6
	1.0f, -1.0f, 1.0f, 1.0f, //b
	-1.0f, -1.0f, 1.0, 1.0, //a
	-1.0f, -1.0f, -1.0f, 1.0f, //m
	1.0f, -1.0f, 1.0f, 1.0f, //b
	-1.0f, -1.0f, -1.0f, 1.0f, //m
	1.0f, -1.0f, -1.0f, 1.0f, //n
																																 
};

GLfloat vertexColors[] = {

	1.0f, 1.0f, 0.0f, 0.5f,
	1.0f, 1.0f, 0.0f, 0.5f,
	1.0f, 1.0f, 0.0f, 0.5f,
	1.0f, 0.0f, 1.0f, 0.5f,
	1.0f, 10.0f, 0.0f, 0.5f,
	1.0f, 30.0f, 0.0f, 0.5f,


	1.0f, 1.0f, 0.0f, 0.5f,
	1.0f, 1.0f, 0.0f, 0.5f,
	1.0f, 1.0f, 0.0f, 0.5f,
	1.0f, 1.0f, 0.0f, 0.5f,
	1.0f, 1.0f, 0.0f, 0.5f,
	0.0f, 1.0f, 0.0f, 0.5f,


	1.0f, 0.0f, 1.0f, 0.5f,
	1.0f, 0.0f, 1.0f, 0.5f,
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
	1.0f, 1.65f, 1.0f, 0.0f,
	1.0f, 1.65f, 1.0f, 0.0f,
	1.0f, 1.65f, 0.0f, 0.0f,
	1.0f, 0.65f, 1.0f, 0.0f,
};

void Application::setup()
{
	std::string strVertexShader = loadTextFile("Shaders\\vertex.vs");
	std::string strFragmentShader = loadTextFile("Shaders\\fragment.fs");

	InitializeProgram(cube1.shader, strVertexShader, strFragmentShader);
	idTransform = glGetUniformLocation(cube1.shader, "transform");

	cube1.numVertex = 36; //Numero de vertices
	glGenVertexArrays(1, &cube1.vao);
	glBindVertexArray(cube1.vao);
	glGenBuffers(1, &cube1.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, cube1.vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions) + sizeof(vertexColors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, sizeof(vertexPositions), vertexPositions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexPositions), sizeof(vertexColors), vertexColors);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(vertexPositions));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

}

Application::Application() : eye(0.0f, 0.0f, 7.0f),
target(0.0f, 0.0f, 0.0f),
transform(glm::mat4(1.0f)),
angles(1.0f, 0.0f, 0.0f)
{}

Application::~Application()
{}

void Application::display()
{
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Seleccionamos los shaders a usar
	glUseProgram(cube1.shader);
	glBindVertexArray(cube1.vao);
	//activamos el vertex array object y dibujamos

	glUniformMatrix4fv(idTransform, 1, GL_FALSE, glm::value_ptr(transformCube2));
	glDrawArrays(GL_TRIANGLES, 0, cube1.numVertex);

	glUniformMatrix4fv(idTransform, 1, GL_FALSE, glm::value_ptr(transformCube3));
	glDrawArrays(GL_TRIANGLES, 0, cube1.numVertex);
}

void Application::update()
{
	angles.x += 0.01f;
	angles.y += 0.01f;
	camera = glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f));
	transform = glm::rotate(glm::mat4(1.0f), glm::radians(angles.x), glm::vec3(1.0f, 0.0f, 0.0f));
	transform = glm::rotate(transform, glm::radians(angles.y), glm::vec3(0.0f, 1.0f, 0.0f));
	transform = glm::perspective(45.0f, 1.35f, 0.1f, 10.0f) *
		camera * transform;

	transformCube2 = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.0f, 0.0f));
	transformCube2 = transformCube2 * transform;

	transformCube3 = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.0f, 0.0f));
	transformCube3 = transformCube3 * transform;
}


void Application::keyboard(int key, int scancode, int actions, int mods)
{

}

void Application::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}





