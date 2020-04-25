#include "lib/leetlib.h"

#include "SingleSkinGameActor.h"

SingleSkinGameActor::SingleSkinGameActor(void * skin) {
	this->skin = skin;
	this->position[0] = 0;
	this->position[1] = 0;
	this->size[0] = 0;
	this->size[1] = 0;
	this->angle = 0.f;
}

SingleSkinGameActor::SingleSkinGameActor(const char * skinFilename) :
	SingleSkinGameActor(LoadSprite(skinFilename)) {}

void SingleSkinGameActor::draw() {
	DrawSprite(
		this->skin,
		this->position[0], this->position[1],
		this->size[0], this->size[1],
		this->angle,
		0xffffffff
	);
}