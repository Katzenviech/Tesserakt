#include "Renderer.h"
#include "Player.h"
#include "Controller.h"
#include "Game.h"

int main(int argc, char* argv[]){
	
	/* CONSTANTS */
	constexpr int WIDTH      =         800;
	constexpr int HEIGHT     =         600;
	constexpr int SIZE       =          30;
	constexpr int FPS        =          60;
	constexpr int SPEED      = (36000/FPS);
	constexpr int MSPERFRAME =  (1000/FPS);

	Renderer renderer(WIDTH, HEIGHT, SIZE);
	Player player((WIDTH-SIZE)/2.0f, (HEIGHT-SIZE)/2.0f, 0.f, 0.f, SPEED, WIDTH, HEIGHT, SIZE);
	Controller controller;
	Game game;

	/* Main loop */
	game.run(controller, renderer, player, MSPERFRAME);

	return 0;
}
