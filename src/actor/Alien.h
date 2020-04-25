#pragma once
#include "game/SingleSkinGameActor.h"

class Alien : public SingleSkinGameActor {
private:
	unsigned int id;
	unsigned int basePosition[2];

	void move(unsigned int time);
	void moveToOffset(unsigned int dx, unsigned int dy);

public:
	Alien(unsigned int id, void * skin);
	virtual void tick(unsigned int time);
};

