#include "Renderer.h"
#include "Player.h"
#include "Controller.h"
#include "Game.h"

int main(int argc, char* argv[]){
	
	/* CONSTANTS */
	constexpr int WIDTH      =        800;
	constexpr int HEIGHT     =        600;
	constexpr int SIZE       =         20;
	constexpr int SPEED      =        600;
	constexpr int GRAVITY    =         60;
	constexpr int FPS        =         60;
	constexpr int JUMP       =      -1500;
	constexpr int MSPERFRAME = (1000/FPS);

	Renderer renderer(WIDTH, HEIGHT, SIZE);
	Player player((WIDTH-SIZE)/2.0f, (HEIGHT-SIZE)/2.0f, 0.f, 0.f, SPEED, JUMP, WIDTH, HEIGHT, SIZE);
	Controller controller;
	Game game(GRAVITY);

	/* Main loop */
	game.run(controller, renderer, player, MSPERFRAME);

	return 0;
}
