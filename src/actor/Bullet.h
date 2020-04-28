#pragma once
#include "SkinGameActor.h"

class GameEngine;
class SpaceBattle;
class Alien;

class Bullet : public SkinGameActor {
private:
	Vector<int> speed;
	void kill(SpaceBattle & battle, Alien * alien);

protected:
	virtual void * getSkin() const;

public:
	Bullet();

	virtual bool isA(const SpaceBattleActorType & type) {
		return type == BULLET;
	}

	virtual void tick(GameEngine & engine);
	virtual void check(GameEngine & engine);

	void setDirection(const Vector<int> & direction) {
		this->speed = direction;
	}
	bool missed() const {
		return this->position.y < 0;
	}
};

