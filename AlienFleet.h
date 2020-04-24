#pragma once
#include <forward_list>

#include "GameActor.h"
#include "Alien.h"

class AlienFleet : public GameActor {
private:
	std::forward_list<Alien*> aliens;
public:
	AlienFleet(unsigned int size);
	~AlienFleet();

	virtual void tick(unsigned int time);
	virtual void draw();
};

