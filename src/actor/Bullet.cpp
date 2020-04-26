#include "Bullet.h"

#define BULLET_SKIN_FILENAME	"gfx/bullet.png"
#define BULLET_SIZE				10
#define BULLET_SPEED			4
#define BULLET_ROTATION_SPEED	.1f

Bullet::Bullet() :
	SingleSkinGameActor(BULLET_SKIN_FILENAME)
{
	this->speed = -BULLET_SPEED;
	this->setSize(BULLET_SIZE, BULLET_SIZE);
}

void Bullet::tick(unsigned int time) {
	this->move(0, this->speed);
	this->rotate(BULLET_ROTATION_SPEED);
}