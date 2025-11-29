#include "SwagBall.h"

void SwagBall::initShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand()%10+10));
	sf::Color color(rand() % 256, rand() % 256, rand() % 256);
	this->shape.setFillColor(color);
	this->shape.setPosition(
		static_cast<float>(rand() % (window.getSize().x - static_cast<unsigned int>(this->shape.getRadius() * 2))),
		static_cast<float>(rand() % (window.getSize().y - static_cast<unsigned int>(this->shape.getRadius() * 2)))
	);
}

SwagBall::SwagBall(const sf::RenderWindow& window)
{
	this->initShape(window);
}

SwagBall::~SwagBall()
{
}

const sf::CircleShape& SwagBall::getShape() const {
	return this->shape;
}

void SwagBall::update() {

}

void SwagBall::render(sf::RenderTarget& target) {
	target.draw(this->shape);
}