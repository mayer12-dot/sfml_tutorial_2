#pragma once

#include <iostream>
#include "Player.h"
#include "SwagBall.h"

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

	void setBackgroundTexture(const std::string & filename);

private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	float spawnTimer;
	float spawnTimerMax;
	int maxSwagBalls;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	Player player;

	std::vector<SwagBall> swagBalls;

	void spawnSwagBalls();
	void updateCollision();
	void initWindow();
	void initVariables();
};

