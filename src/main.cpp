#include <vector>
#include "Renderer.h"
#include "Player.h"
#include "Controller.h"
#include "Game.h"
#include "Bullet.h"
#include "Enemy.h"

int main(int argc, char* argv[]){
	
	/* CONSTANTS */
	constexpr int WIDTH         =         800; // pixel
	constexpr int HEIGHT        =         600; // pixel
	constexpr int SIZE          =          30; // pixel
	constexpr int FPS           =          75; // frames per second
	constexpr int SPEED         =         500; // pixel/s
	constexpr int BULLETSPEED   =         800; // pixel/s
	constexpr int TIMEBETWSHOTS =         100; // ms
	constexpr int ENEMYMOVEPCT  =          25; // move speed enemy in % of player speed
	constexpr int MSPERFRAME    =  (1000/FPS); // ms per frame
	constexpr int STUNTIMEMS    =        2000; // stuntime in ms
	constexpr int SPAWNTIME     =        1000; // time between spawns in ms
	constexpr int SPEEDINCENPRC =           1; // speed increase of enemies in percent (if not stunned)

	Renderer renderer(WIDTH, HEIGHT, SIZE);
	Player player((WIDTH-SIZE)/2.0f, (HEIGHT-SIZE)/2.0f, 0.f, 0.f, SPEED, WIDTH, HEIGHT, SIZE);
	std::vector<Bullet> bullets;
	std::vector<Enemy> enemies;
	Controller controller;
	Game game(BULLETSPEED, TIMEBETWSHOTS, ENEMYMOVEPCT, STUNTIMEMS, SPAWNTIME, SPEEDINCENPRC, WIDTH, HEIGHT, SIZE);

	/* Main loop */
	game.run(controller, renderer, player, bullets, enemies, MSPERFRAME);

	return 0;
}
