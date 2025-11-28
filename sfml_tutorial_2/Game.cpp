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

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent)) {
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();

	this->player.update(*this->window);
}

void Game::render()
{
	this->window->clear();
	
	this->window->draw(this->backgroundSprite);

	//Draw here
	this->player.render(*this->window);

	this->window->display();
}

void Game::setBackgroundTexture(const std::string& filename)
{
	if (!this->backgroundTexture.loadFromFile(filename)) {
		std::cerr << "ERROR::GAME::COULD NOT LOAD BACKGROUND TEXTURE FROM FILE: " << filename << "\n";
		return;
	}

	backgroundSprite.setTexture(this->backgroundTexture);

	sf::Vector2u textureSize = this->backgroundTexture.getSize();
	sf::Vector2u windowSize = this->window->getSize();

	backgroundSprite.setScale(
		static_cast<float>(windowSize.x) / static_cast<float>(textureSize.x),
		static_cast<float>(windowSize.y) / static_cast<float>(textureSize.y)
	);
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initVariables()
{
	this->endGame = false;
}

//Functions

