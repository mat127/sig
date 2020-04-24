#pragma once
#include "PlayerShip.h"
#include "AlienFleet.h"

class SpaceInvadersGame {
private:
	unsigned int time;
	PlayerShip ship;
	AlienFleet aliens;

public:
	SpaceInvadersGame();
	void run();
	void tick();
	void draw();
};

