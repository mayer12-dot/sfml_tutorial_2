#include "SwagBall.h"

void SwagBall::initShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand()%10+10));

	sf::Color color;
	switch (this->type)
	{
	case DEFAULT:
		color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
		break;
	case DAMAGING:
		color = sf::Color::Red;
		this->shape.setOutlineColor(sf::Color::Black);
		this->shape.setOutlineThickness(2.f);
		break;
	case HEALING:
		color = sf::Color::Green;
		this->shape.setOutlineColor(sf::Color::White);
		this->shape.setOutlineThickness(2.f);
		break;
	default:
		break;
	}
	this->shape.setFillColor(color);
	this->shape.setPosition(
		static_cast<float>(rand() % (window.getSize().x - static_cast<unsigned int>(this->shape.getRadius() * 2))),
		static_cast<float>(rand() % (window.getSize().y - static_cast<unsigned int>(this->shape.getRadius() * 2)))
	);
}

SwagBall::SwagBall(const sf::RenderWindow& window, int type) : type(type)
{
	this->initShape(window);
}

SwagBall::~SwagBall()
{
}

const sf::CircleShape& SwagBall::getShape() const {
	return this->shape;
}

const int& SwagBall::getType() const
{
	return this->type;
}

void SwagBall::update() {

}

void SwagBall::render(sf::RenderTarget& target) {
	target.draw(this->shape);
}