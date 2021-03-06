#ifndef GAME_H
#define GAME_H

#include <Debug.h>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <fstream>

#include "Vector3.h"
#include "Matrix3.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();
	std::string readShader(std::string t_fileName);

	sf::Clock clock;
	sf::Time elapsed;

	float rotationAngle = 0.0f;
};

#endif