#pragma once
#include "actor/PlayerShip.h"
#include "actor/AlienFleet.h"

class SpaceInvadersGame {
private:
	unsigned int time;
	PlayerShip ship;
	AlienFleet aliens;

	void tick();
	void draw();

	void checkCollisions();
	void checkAlienBulletHits();
	void checkShipAlienCollisions();

public:
	SpaceInvadersGame();
	void run();
};

