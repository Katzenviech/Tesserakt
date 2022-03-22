#include <vector>
#include "Renderer.h"
#include "Player.h"
#include "Controller.h"
#include "Game.h"
#include "Bullet.h"

int main(int argc, char* argv[]){
	
	/* CONSTANTS */
	constexpr int WIDTH         =         800;
	constexpr int HEIGHT        =         600;
	constexpr int SIZE          =          30;
	constexpr int FPS           =          75;
	constexpr int SPEED         =         600; // pixel/s
	constexpr int BULLETSPEED   =        1000; // pixel/s
	constexpr int TIMEBETWSHOTS =         200; //ms
	constexpr int MSPERFRAME    =  (1000/FPS);

	Renderer renderer(WIDTH, HEIGHT, SIZE);
	Player player((WIDTH-SIZE)/2.0f, (HEIGHT-SIZE)/2.0f, 0.f, 0.f, SPEED, WIDTH, HEIGHT, SIZE);
	std::vector<Bullet> bullets;
	Controller controller;
	Game game(BULLETSPEED, TIMEBETWSHOTS);

	/* Main loop */
	game.run(controller, renderer, player, bullets, MSPERFRAME);

	return 0;
}
