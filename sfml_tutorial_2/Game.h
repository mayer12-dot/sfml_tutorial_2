#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
public:
	//Constructor / Destructor

	Game();
	~Game();

	//Accessors

	//Modifiers

	//Functions
	const bool running() const;
	void pollEvents();

	void update();

	void render();

private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	void initWindow();
	void initVariables();
};

