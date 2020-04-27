#define _USE_MATH_DEFINES
#include <cmath>

#include "Alien.h"
#include "PlayerShip.h"
#include "Explosion.h"
#include "game/SpaceBattle.h"
#include "util/SkinLoader.h"
#include "util/JukeBox.h"

#define ALIEN_SKIN_FILENAME "gfx/Little Invader.png"

Alien::Alien(unsigned int id) :
	SkinGameActor(),
	id(id)
{
	this->basePosition.x = (id % 10) * 60 + 120;
	this->basePosition.y = (id / 10) * 60 + 70;
	this->setSize(10 + (id % 17));
}

void * Alien::getSkin() const {
	return SkinLoader::getSkin(ALIEN_SKIN_FILENAME);
}

void Alien::tick(GameEngine & engine) {
	this->move(engine.getTime());
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

void Alien::check(GameEngine & engine) {
	SpaceBattle & battle = (SpaceBattle &)engine;
	PlayerShip * ship = battle.getShip();
	if (ship == nullptr)
		return;
	else if (!this->hit(*ship))
		return;
	ship->explode(battle);
	this->explodeSilently(battle);
}

void Alien::explodeSilently(SpaceBattle & battle) {
	Explosion * explosion = new Explosion(*this);
	battle.remove(this);
	battle.add(explosion);
}

void Alien::explode(SpaceBattle & battle) {
	this->explodeSilently(battle);
	JukeBox::alienExplosion();
}