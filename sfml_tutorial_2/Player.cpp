#include "Player.h"


void Player::initVariables()
{
	this->movementSpeed = 5.f;
	this->hpMax = 10;
	this->hp = this->hpMax;
	this->points = 0;
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

void Player::updateInput()
{
	//Keyboard input
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape.move(-this->movementSpeed, 0.f);
	}
	//Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape.move(this->movementSpeed, 0.f);
	}

	//Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->shape.move(0.f, -this->movementSpeed);
	}
	//Down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->shape.move(0.f, this->movementSpeed);
	}
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget& target)
{
	sf::FloatRect pos = this->shape.getGlobalBounds();
	sf::Vector2f size = this->shape.getSize();
	sf::Vector2u windowSize = target.getSize();

	//this is added to prevent the player from going outside the window bounds if 
	//top and left are both pressed
	float newX = pos.left;
	float newY = pos.top;

	if (pos.left <= 0.f)
	{
		newX = 0.f;
	}
	else if (pos.left + size.x >= windowSize.x) {
		newX = windowSize.x - size.x;
	}

	if (pos.top <= 0.f) {
		newY = 0.f;
	}
	else if (pos.top + size.y >= windowSize.y) {
		newY = windowSize.y - size.y;
	}

	this->shape.setPosition(newX, newY);
}

void Player::update(sf::RenderTarget& target)
{
	this->updateInput();

	//Window bounds check
	this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

Player::Player(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initShape();
	this->initVariables();
}

Player::~Player()
{
}

const sf::RectangleShape& Player::getShape() const
{
	return this->shape;
}
