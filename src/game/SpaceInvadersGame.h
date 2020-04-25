#pragma once
#include "actor/PlayerShip.h"
#include "actor/AlienFleet.h"

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

