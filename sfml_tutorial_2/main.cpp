#include "Game.h"
#include <cmath>
int main() {

	//initialize random seed
	srand(static_cast<unsigned int>(time(0)));

	//Initialize game object
	Game game;

	game.setBackgroundTexture("Resources/wood_texture.jpg");

	//Game loop
	while (game.running()) {
		
		//Update
		game.update();

		//Render
		game.render();
	}

	//end of application
    
	return 0;
}
/* KOTRLJANJE KRUGA - PRIMER
* sf::RenderWindow window(sf::VideoMode(800, 600), "Rolling Circle");

    float radius = 50.f;
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(3);
    circle.setOutlineColor(sf::Color::White);
    circle.setOrigin(radius, radius);
    circle.setPosition(200, 300);

    // Linija koja ide od centra do oboda – poluprecnik
    sf::RectangleShape radiusLine(sf::Vector2f(radius, 3));
    radiusLine.setFillColor(sf::Color::Red);
    radiusLine.setOrigin(0, 1.5f);

    float speed = 150.f; // px/s
    float angle = 0.f;   // trenutni ugao rotacije

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        float dt = clock.restart().asSeconds();

        float dx = speed * dt;         // horizontalno pomeranje
        float dAngle = (dx / radius);  // radijani koje treba rotirati
        float dAngleDeg = dAngle * 180.f / 3.14159265f;

        // Translacija + rotacija
        circle.move(dx, 0);
        circle.rotate(dAngleDeg);

        // Linija prati rotaciju i poziciju kruga
        radiusLine.setPosition(circle.getPosition());
        radiusLine.setRotation(circle.getRotation());

        window.clear();
        window.draw(circle);
        window.draw(radiusLine);
        window.display();
    }
*/