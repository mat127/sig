#pragma once
#include "PlayerShip.h"

class SpaceInvadersGame {
private:
	unsigned int time;
	PlayerShip ship;

	void initialize();

public:
	SpaceInvadersGame() : ship(400), time(0u) {
		ship.setPositionRange(0, SCREEN_X);
	}
	void run();
	void tick();
	void draw();
};

