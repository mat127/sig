#include "lib/leetlib.h"

#include "SpaceInvadersGame.h"

SpaceInvadersGame::SpaceInvadersGame() :
	ship(400),
	aliens(50),
	time(0u)
{
	ship.setPositionRange(0, SCREEN_X);
}

void SpaceInvadersGame::run() {
	while (!WantQuit() && !IsKeyDown(VK_ESCAPE)) {
		this->tick();
		this->draw();
	}
}

void SpaceInvadersGame::tick() {
	this->time++;
	this->ship.tick(this->time);
	this->aliens.tick(this->time);
}

void SpaceInvadersGame::draw() {
	this->ship.draw();
	this->aliens.draw();
	Flip();
}
