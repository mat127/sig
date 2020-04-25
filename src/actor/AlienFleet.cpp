#include "lib/leetlib.h"

#include "AlienFleet.h"
#include "util/SkinLoader.h"

AlienFleet::AlienFleet(unsigned int size)
	: aliens() 
{
	void * skin = SkinLoader::getSkin("gfx/Little Invader.png");
	for (unsigned int i = 0; i < size; i++) {
		Alien * alien = new Alien(i, skin);
		this->aliens.push_front(alien);
	}
}

AlienFleet::~AlienFleet() {
	for (auto it = this->aliens.begin(); it != this->aliens.end(); it++) {
		delete (*it);
	}
}

void AlienFleet::tick(unsigned int time) {
	for (auto it = this->aliens.begin(); it != this->aliens.end(); it++) {
		(*it)->tick(time);
	}
}

void AlienFleet::draw() {
	for(auto it = this->aliens.begin(); it != this->aliens.end(); it++) {
		(*it)->draw();
	}
}
