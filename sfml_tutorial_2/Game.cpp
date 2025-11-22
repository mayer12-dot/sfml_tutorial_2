#include "Game.h"

//Constructor / Destructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::update()
{
}

void Game::render()
{
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initVariables()
{
	this->endGame = false;
}

//Functions

