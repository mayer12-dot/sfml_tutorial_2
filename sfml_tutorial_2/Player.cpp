#include "Player.h"


void Player::initVariables()
{
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));

}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

Player::Player()
{
	this->initShape();
	this->initVariables();
}

Player::~Player()
{
}