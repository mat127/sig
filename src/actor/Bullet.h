#pragma once
#include "game/SingleSkinGameActor.h"

class Bullet : public SingleSkinGameActor {
private:
	unsigned int speed;
public:
	Bullet();
	virtual void tick(unsigned int time);
	inline bool missed() const {
		return this->position.y < 0;
	}
};

