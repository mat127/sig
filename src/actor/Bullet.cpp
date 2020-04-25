#include "Bullet.h"

Bullet::Bullet(void * skin) :
	SingleSkinGameActor(skin)
{
	this->speed = -4;
	this->setSize(10, 10);
}

void Bullet::tick(unsigned int time) {
	this->move(0, this->speed);
	this->rotate(0.1f);
}