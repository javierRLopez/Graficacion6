#pragma once

#include <iostream>
#include "Object3D.h"
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"

class Application {
public:
	GLFWwindow* window;


	Application();
	~Application();


	void setup();
	void update();
	void display();
	void reshape(int w, int h);
	void keyboard(int key, int scancode, int actions, int mods);


private:
	Object3D cube;
	glm::mat4 camera;
	glm::vec3 eye, target, angles;
	glm::mat4 transform;

	GLuint idTransform;
};

