#define _USE_MATH_DEFINES
#include <cmath>

#include "Alien.h"

Alien::Alien(unsigned int id, void * skin) :
	SingleSkinGameActor(skin), id(id)
{
	this->basePosition[0] = (id % 10) * 60 + 120;
	this->basePosition[1] = (id / 10) * 60 + 70;
	this->setSize(10 + (id % 17));
}

void Alien::tick(unsigned int time) {
	this->move(time);
}

void Alien::move(unsigned int time) {
	int xo = 0, yo = 0;
	int n = this->id;
	int n1 = time + n*n + n*n*n;
	int n2 = time + n + n*n + n*n*n * 3;
	if (((n1 >> 6) & 0x7) == 0x7)xo += (1 - cos((n1 & 0x7f) / 64.0f*2.f*3.141592))*(20 + ((n*n) % 9));
	if (((n1 >> 6) & 0x7) == 0x7)yo += (sin((n1 & 0x7f) / 64.0f*2.f*3.141592))*(20 + ((n*n) % 9));
	if (((n2 >> 8) & 0xf) == 0xf)yo += (1 - cos((n2 & 0xff) / 256.0f*2.f*3.141592))*(150 + ((n*n) % 9));
	this->moveToOffset(xo, yo);
}

void Alien::moveToOffset(unsigned int dx, unsigned int dy) {
	this->setPosition(this->basePosition[0] + dx, this->basePosition[1] + dy);
}
