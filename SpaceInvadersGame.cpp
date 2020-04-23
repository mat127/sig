#include "lib/leetlib.h"

#include "SpaceInvadersGame.h"

void SpaceInvadersGame::initialize() {
	PlayerShip::loadSkin();
}

void SpaceInvadersGame::run() {
	this->initialize();
	while (!WantQuit() && !IsKeyDown(VK_ESCAPE)) {
		this->tick();
		this->draw();
	}
}

void SpaceInvadersGame::tick() {
	this->time++;
	this->ship.tick(this->time);
}

void SpaceInvadersGame::draw() {
	this->ship.draw();
	Flip();
}
