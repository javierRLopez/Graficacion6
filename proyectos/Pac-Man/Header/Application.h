#pragma once

#include <iostream>
#include "Object3D.h"
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"
#include "PacMan.h"
#include "Enemies.h"

class Application {
public:
	GLFWwindow* window;


	Application();
	~Application();

	GLint pacMap[20][20] =
	{
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
		1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,
		1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,
		1,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,1,
		1,2,1,1,2,1,1,2,1,1,1,1,2,1,1,2,1,1,2,1,
		1,2,1,1,2,1,1,2,1,1,1,1,2,1,1,2,1,1,2,1,
		1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
		1,1,1,1,2,1,1,1,1,0,0,1,1,1,1,2,1,1,1,1,
		1,2,2,2,2,1,0,0,0,0,0,0,0,0,1,2,2,2,2,1,
		1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,
		1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
		1,2,1,1,2,1,1,2,1,1,1,1,2,1,1,2,1,1,2,1,
		1,2,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,2,1,
		1,2,2,2,2,1,1,2,2,2,2,2,2,1,1,2,2,2,2,1,
		1,2,1,1,2,1,1,2,1,1,1,1,2,1,1,2,1,1,2,1,
		1,2,1,1,2,1,1,2,1,1,1,1,2,1,1,2,1,1,2,1,
		1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};


	void setup();
	void update();
	void display();
	void reshape(int w, int h);
	void keyboard(int key, int scancode, int actions, int mods);
	void firstPerson();
	void miniMap();
	void display2();
	void editor();
	void up();
	void right();
	void left();
	void down();

	void enemieUP(Enemies &enemigo);
	void enemyRight(Enemies &enemigo2);
	void enemyDown(Enemies &enemigo);
	void enemyLeft(Enemies &enemigo);

	void enemyMovement(Enemies &enemigo);

private:
	Object3D Cube;
	PacMan gamer;
	Enemies fan,fan2;

	glm::mat4 camera;
	glm::vec3 eye, target,angles;
	glm::mat4 transform;

	bool isfirstPerson1 = false;
	bool isEdit = false; 

	GLuint idTransform;

	float move = 0;

};
