#define _USE_MATH_DEFINES
#include <cmath>

#include "Alien.h"

Alien::Alien(unsigned int id) :
	SingleSkinGameActor("gfx/Little Invader.png"),
	id(id)
{
	this->basePosition.x = (id % 10) * 60 + 120;
	this->basePosition.y = (id / 10) * 60 + 70;
	this->setSize(10 + (id % 17));
}

void Alien::tick(unsigned int time) {
	this->move(time);
}

void Alien::move(unsigned int time) {
	Vector<int> offset(0,0);
	int n = this->id;
	int n1 = time + n*n + n*n*n;
	int n2 = time + n + n*n + n*n*n * 3;
	if (((n1 >> 6) & 0x7) == 0x7)offset.x += (1 - cos((n1 & 0x7f) / 64.0f*2.f*3.141592))*(20 + ((n*n) % 9));
	if (((n1 >> 6) & 0x7) == 0x7)offset.y += (sin((n1 & 0x7f) / 64.0f*2.f*3.141592))*(20 + ((n*n) % 9));
	if (((n2 >> 8) & 0xf) == 0xf)offset.y += (1 - cos((n2 & 0xff) / 256.0f*2.f*3.141592))*(150 + ((n*n) % 9));
	this->moveTo(offset);
}