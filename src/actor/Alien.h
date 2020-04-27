#pragma once
#include "SkinGameActor.h"
#include "util/Vector.h"

class SpaceBattle;

class Alien : public SkinGameActor {
private:
	unsigned int id;
	Vector<int> basePosition;

	void move(unsigned int time);
	void moveTo(const Vector<int> & offset) {
		this->setPosition(this->basePosition + offset);
	}

protected:
	virtual void * getSkin() const;

public:
	Alien(unsigned int id);

	virtual bool isA(const SpaceBattleActorType & type) {
		return type == ALIEN;
	}

	static Alien * cast(GameActor * actor) {
		return ((SpaceBattleActor *)actor)->isA(ALIEN) ? (Alien *)actor : nullptr;
	}
	virtual void tick(GameEngine & engine);
	virtual void check(GameEngine & engine);

	unsigned int getScore() const {
		return 30u - this->size.x; // smaller is better
	}

	void explode(SpaceBattle & battle);
	void explodeSilently(SpaceBattle & battle);
};

