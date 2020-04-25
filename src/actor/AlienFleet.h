#pragma once
#include <forward_list>

#include "game/GameActor.h"
#include "Alien.h"

class AlienFleet : public GameActor {
private:
	std::forward_list<Alien*> aliens;
public:
	AlienFleet(unsigned int size);
	~AlienFleet();

	virtual void tick(unsigned int time);
	virtual void draw();

	std::forward_list<Alien *>::iterator begin() {
		return aliens.begin();
	}
	std::forward_list<Alien *>::iterator end() {
		return aliens.end();
	}
	void remove(Alien * alien) {
		aliens.remove(alien);
		delete alien;
	}
};

