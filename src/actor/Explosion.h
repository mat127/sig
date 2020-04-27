#pragma once

#include "AnimatedGameActor.h"

class Explosion : public AnimatedGameActor {
protected:
	virtual void * getSkin(unsigned int frameIndex) const;
public:
	Explosion();
	Explosion(const SkinGameActor & actor);
	virtual void check(GameEngine & engine);
};