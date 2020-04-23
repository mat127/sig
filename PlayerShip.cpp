#define _USE_MATH_DEFINES
#include <cmath>

#include "lib/leetlib.h"

#include "PlayerShip.h"

void * PlayerShip::skin;

const unsigned int PlayerShip::verticalPosition = 550;
const unsigned int PlayerShip::size[] = { 50, 50 };
const int PlayerShip::stepSize = 7;

void PlayerShip::loadSkin() {
	PlayerShip::skin = LoadSprite("gfx/Big Invader.png");
}

void PlayerShip::draw() {
	DrawSprite(
		PlayerShip::skin,
		this->position, PlayerShip::verticalPosition,
		PlayerShip::size[0], PlayerShip::size[0],
		this->angle,
		0xffffffff
	);
}

void PlayerShip::tick(unsigned int time) {
	if (IsKeyDown(VK_LEFT) && this->canMoveLeft())
		this->moveLeft();
	if (IsKeyDown(VK_RIGHT) && this->canMoveRight())
		this->moveRight();
	this->setAngle(M_PI + sin(time*0.1)*0.1);
}
