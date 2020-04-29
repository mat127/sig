#include <cstdio>

#include "Explosion.h"
#include "game/SpaceBattle.h"
#include "util/SkinLoader.h"

#define FRAME_COUNT 7u

Explosion::Explosion() :
	AnimatedGameActor(FRAME_COUNT) {}

Explosion::Explosion(const SkinGameActor & actor) :
	Explosion()
{
	this->setPosition(actor.getPosition());
	this->setSize(actor.getSize());
}

void Explosion::check(GameEngine & engine) {
	AnimatedGameActor::check(engine);
	if(this->isOver())
		engine.remove(this);
}

void * Explosion::getSkin(unsigned int frameIndex) const {
	char buffer[64];
	snprintf(buffer, sizeof(buffer), "gfx/explosion-%1u.png", frameIndex);
	return SkinLoader::getSkin(buffer);
}