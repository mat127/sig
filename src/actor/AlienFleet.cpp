#include "lib/leetlib.h"

#include "AlienFleet.h"
#include "util/SkinLoader.h"

AlienFleet::AlienFleet(unsigned int size)
	: aliens() 
{
	for(unsigned int i = 0; i < size; i++) {
		Alien * alien = new Alien(i);
		this->aliens.push_front(alien);
	}
}

AlienFleet::~AlienFleet() {
	for(Alien * alien : this->aliens)
		delete alien;
}

void AlienFleet::tick(unsigned int time) {
	for (Alien * alien : this->aliens)
		alien->tick(time);
}

void AlienFleet::draw() {
	for (Alien * alien : this->aliens)
		alien->draw();
}
