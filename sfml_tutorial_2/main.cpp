#include "Game.h"

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