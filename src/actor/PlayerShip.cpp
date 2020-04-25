#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "lib/leetlib.h"

#include "PlayerShip.h"

PlayerShip::PlayerShip(unsigned int position) :
	SingleSkinGameActor("gfx/Big Invader.png"), gun(*this)
{
	this->setPosition(position, 550);
	this->setSize(50);
	this->stepSize = 7;
}

void PlayerShip::tick(unsigned int time) {
	if (IsKeyDown(VK_LEFT) && this->canMoveLeft())
		this->moveLeft();
	if (IsKeyDown(VK_RIGHT) && this->canMoveRight())
		this->moveRight();
	this->rotate(time);
	this->gun.tick(time);
}

void PlayerShip::draw() {
	SingleSkinGameActor::draw();
	this->gun.draw();
}

void PlayerShip::rotate(unsigned int time) {
	this->setAngle(M_PI + sin(time*0.1f)*0.1f);
}

bool PlayerShip::canMoveLeft() {
	int bound = this->getLeftBound();
	return bound - (int)stepSize >= this->positionRange[0];
}

bool PlayerShip::canMoveRight() {
	int bound = this->getRightBound();
	return bound + stepSize <= this->positionRange[1];
}
