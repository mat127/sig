#pragma once
#include "game/SingleSkinGameActor.h"
#include "util/Vector.h"

class Alien : public SingleSkinGameActor {
private:
	unsigned int id;
	Vector<int> basePosition;

	void move(unsigned int time);
	void moveTo(const Vector<int> & offset) {
		this->setPosition(this->basePosition + offset);
	}

public:
	Alien(unsigned int id, void * skin);
	virtual void tick(unsigned int time);
	unsigned int getScore() const {
		return 30u - this->size.x; // smaller is better
	}
};

