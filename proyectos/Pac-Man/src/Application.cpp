#include "Application.h"
#include <iostream>
#include <vector>

#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


#include "ShaderFuncs.h"

std::vector<GLfloat> vertexPositions = {
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






Application::Application() : eye(10.0f, 30.0f, 200.0f),
target(10.0f, -10.0f, 0.0f),
transform(glm::mat4(1.0f)),
angles(0.0f, 0.0f, 0.0f)
{}

Application::~Application()
{}

void Application::update()
{
	
	camera = glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f));
	
}

void Application::keyboard(int key, int scancode, int actions, int mods)
{
	if (actions == GLFW_RELEASE)
	{
		switch (key)
		{
		case GLFW_KEY_W:
			up();
			break;
		case GLFW_KEY_D:
			right();
			
			break;
		case GLFW_KEY_S:
			down();
			break;
		case GLFW_KEY_A:
			left();

			break;
		case GLFW_KEY_H:
			isfirstPerson1 = true;
			
			break;
		case GLFW_KEY_B:
			isfirstPerson1 = false;
			break;
		}
	}
	
}

void Application::firstPerson()
{
	eye = glm::vec3(gamer.y * 2.0f, 0.0f, gamer.x*2.0f - 1.5f);
	target = eye;
	target.z -= 5.0f;

	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			transform = glm::translate(glm::mat4(1.0f), glm::vec3(i*2, 0, j*2));
			transform = glm::perspective(45.0f, 1.0f, 0.7f, 100.0f) *
				camera * transform;

			if (pacMap[j][i] == 1)
				Cube.draw(transform, glm::vec4(0.0f, 0.0f, 1.0f, 50.0f));
			if (pacMap[j][i] == 2)
				Cube.draw(glm::scale(transform, glm::vec3(0.2f, 0.2f, 0.2f)), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
			if (pacMap[j][i] == 3)
				Cube.draw(glm::scale(transform, glm::vec3(0.5f, 0.5f, 0.5f)), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
			if (pacMap[j][i] == 4)
				Cube.draw(glm::scale(transform, glm::vec3(0.5f, 0.5f, 0.5f)), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
		}
	}

	system("cls");
}


void Application::editor()
{
	
	eye = glm::vec3(10.0f, 70.0f, 10.0f);
	target = glm::vec3(10.0f, -10.0f, 0.0f);


	
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			transform = glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10, j * 2));
			transform = glm::perspective(20.0f, 1.0f, 10.1f, -10.f) *
				camera * transform;

			if (pacMap[j][i] == 1)
				Cube.draw(transform, glm::vec4(0.0f, 0.0f, 1.0f, 50.0f));
			if (pacMap[j][i] == 2)
				Cube.draw(glm::scale(transform, glm::vec3(0.2f, 0.2f, 0.2f)), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
			if (pacMap[j][i] == 3)
				Cube.draw(glm::scale(transform, glm::vec3(0.5f, 0.5f, 0.5f)), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
			if (pacMap[j][i] == 4)
				Cube.draw(glm::scale(transform, glm::vec3(0.5f, 0.5f, 0.5f)), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
			if (pacMap[j][i] == 5)
				Cube.draw(glm::scale(transform, glm::vec3(0.2f, 0.2f, 0.2f)), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
		}
	}
	

	

	/*int op = 0,x, y;
	std::cout << "Bienvenido al Editor mapa de 20x20" << std::endl;
	std::cout << "1.-Poner pared" << std::endl;
	std::cout << "2.-Poner camino" << std::endl;
	std::cout << "3.-Poner Dulce" << std::endl;
	std::cout << "4.-Salir" << std::endl;
	std::cout << "Que queires hacer: ";
	std::cin >> op;
	
	switch (op)
	{
	case 1: 
		std::cout << "Defina la posicion de la pared en X: ";
		std::cin >> x;
		std::cout << "Defina la posicion de la pared en Y: ";
		std::cin >> y;

		pacMap[x][y] = 1;
		break;
	case 2:
		std::cout << "Defina la posicion de la pared en X: ";
		std::cin >> x;
		std::cout << "Defina la posicion de la pared en Y: ";
		std::cin >> y;

		pacMap[x][y] = 0;
		break;
	case 3:
		std::cout << "Defina la posicion de la pared en X: ";
		std::cin >> x;
		std::cout << "Defina la posicion de la pared en Y: ";
		std::cin >> y;

		pacMap[x][y] = 2;
		break;
	case 4:
		isfirstPerson = true;
	default:
		break;
	}*/
	system("cls");
}

void Application::miniMap()
{
	
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			transform = glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10, j * 2));
			transform = glm::perspective(20.0f, 1.0f, 10.1f, -10.f) *
				camera * transform;

			if (pacMap[j][i] == 1)
				Cube.draw(transform, glm::vec4(0.0f, 1.0f, 1.0f, 50.0f));
			if (pacMap[j][i] == 2)
				Cube.draw(glm::scale(transform, glm::vec3(0.2f, 0.2f, 0.2f)), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
			if (pacMap[j][i] == 3)
				Cube.draw(glm::scale(transform, glm::vec3(0.5f, 0.5f, 0.5f)), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
			if (pacMap[j][i] == 4)
				Cube.draw(glm::scale(transform, glm::vec3(0.5f, 0.5f, 0.5f)), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
			if (pacMap[j][i] == 5)
				Cube.draw(glm::scale(transform, glm::vec3(0.2f, 0.2f, 0.2f)), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
		}
	}

}

void Application::display2()
{
	miniMap();
}

void Application::setup()
{
	gamer.setup(4, 4);

	fan.setup(7,1);
	fan2.setup(10, 1);

	pacMap[fan.x][fan.y] = 4;
	pacMap[gamer.x][gamer.y] = 3;

	Cube.Shaders("Shaders\\Vertex.vs", "Shaders\\fragment.fs");
	Cube.setup(vertexPositions,NULL);

}



void Application::display()
{
	enemyMovement(fan);
	
	std::cout << isfirstPerson1;
	if (isfirstPerson1)
	{
		firstPerson();

	}
	else
	{
		editor();

	}
	
}

void Application::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}


void Application::up()
{

	int x = gamer.x - 1;
	int y = gamer.y;

	if(pacMap[x][y] == 1)
	{ 
		std::cout << "chocaste ";
	}
	else if (pacMap[x][y] == 2 || pacMap[x][y] == 0)
	{
		pacMap[gamer.x][gamer.y] = 0;
		pacMap[x][y] = 3;
		gamer.x = x;
		gamer.y = y;
	}
	eye = glm::vec3(gamer.y * 2, 0, gamer.x * 2);
	target = eye;
	target.z -= 2.0f;
}

void Application::right()
	{
		int x = gamer.x;
		int y = gamer.y + 1;
		
		if (pacMap[x][y] == 1)
		{
			std::cout << "Chocaste ";
		}
		else if (pacMap[x][y] == 2 || pacMap[x][y] == 0)
		{
			pacMap[gamer.x][gamer.y] = 0;
			pacMap[x][y] = 3;
			gamer.x = x;
			gamer.y = y;
		}
		eye = glm::vec3(gamer.y * 2, 0, gamer.x * 2);
		target = eye;
		target.x += 2.0f;
	}

void Application::left()
	{
		int x = gamer.x;
		int y = gamer.y - 1;

		if (pacMap[x][y] == 1)
		{
			std::cout << "chocaste ";
		}
		else if (pacMap[x][y] == 2 || pacMap[x][y] == 0)
		{
			pacMap[gamer.x][gamer.y] = 0;
			pacMap[x][y] = 3;
			gamer.x = x;
			gamer.y = y;
		}
		eye = glm::vec3(gamer.y * 2, 0, gamer.x * 2);
		target = eye;
		target.x -= 2.0f;
	}

void Application::down()
	{

		int x = gamer.x + 1;
		int y = gamer.y;

		if (pacMap[x][y] == 1)
		{
			std::cout << "chocaste ";
		}
		else if (pacMap[x][y] == 2 || pacMap[x][y] == 0)
		{
			pacMap[gamer.x][gamer.y] = 0;
			pacMap[x][y] = 3;
			gamer.x = x;
			gamer.y = y;
		}
		eye = glm::vec3(gamer.y * 2, 0, gamer.x * 2);
		target = eye;
		target.z += 2.0f;
	}

void Application::enemieUP(Enemies& enemigo)
	{
		int x = enemigo.x -1;
		int y = enemigo.y;

		if (pacMap[x][y] == 1)
		{
			std::cout << "chocaste ";
		}
		else if (pacMap[x][y] == 2)
		{
			pacMap[enemigo.x][enemigo.y] = 2;
			pacMap[x][y] = 4;
			enemigo.x = x;
			enemigo.y = y;
		}
		else if (pacMap[x][y] == 0)
		{
			pacMap[enemigo.x][enemigo.y] = 0;
			pacMap[x][y] = 4;
			enemigo.x = x;
			enemigo.y = y;
		}

	}

void Application::enemyRight(Enemies &enemigo2)
	{
		int x = enemigo2.x;
		int y = enemigo2.y + 1;

		
		 if (pacMap[x][y] == 2)
		{
			pacMap[enemigo2.x][enemigo2.y] = 2;
			pacMap[x][y] = 4;
			enemigo2.x = x;
			enemigo2.y = y;
		}
		else if (pacMap[x][y] == 0)
		{
			pacMap[enemigo2.x][enemigo2.y] = 0;
			pacMap[x][y] = 4;
			enemigo2.x = x;
			enemigo2.y = y;
		}
	}

void Application::enemyDown(Enemies &enemigo)
	{
		int x = enemigo.x + 1;
		int y = enemigo.y;

		if (pacMap[x][y] == 2)
		{
			pacMap[enemigo.x][enemigo.y] = 2;
			pacMap[x][y] = 4;
			enemigo.x = x;
			enemigo.y = y;
		}
		else if (pacMap[x][y] == 0)
		{
			pacMap[enemigo.x][enemigo.y] = 0;
			pacMap[x][y] = 4;
			enemigo.x = x;
			enemigo.y = y;
		}
	}

void Application::enemyLeft(Enemies &enemigo)
	{
		int x = enemigo.x;
		int y = enemigo.y - 1;

		if (pacMap[x][y] == 2)
		{
			pacMap[enemigo.x][enemigo.y] = 2;
			pacMap[x][y] = 4;
			enemigo.x = x;
			enemigo.y = y;
		}
		else if (pacMap[x][y] == 0)
		{
			pacMap[enemigo.x][enemigo.y] = 0;
			pacMap[x][y] = 4;
			enemigo.x = x;
			enemigo.y = y;
		}
	}


bool down1 = false;
void Application::enemyMovement(Enemies &enemigo)
	{
	/*	move += 0.5;
		if (move >= 15)
		{
			if (pacMap[enemigo.x - 1][enemigo.y] == 2)
			{
				enemieUP(enemigo);
			}
			if (pacMap[enemigo.x][enemigo.y] == pacMap[1][4])
			{
				down1 = true;
			}

			move = 0;
		}*/

		
	}