#define NOMINMAX // avoid windows.h max() definition
#include <algorithm>

#include "lib/leetlib.h"

#include "SingleSkinGameActor.h"
#include "util/SkinLoader.h"

SingleSkinGameActor::SingleSkinGameActor(void * skin) :
	skin(skin), position(0,0), size(0,0), angle(0.f) {}

SingleSkinGameActor::SingleSkinGameActor(const char * skinFilename) :
	SingleSkinGameActor(SkinLoader::getSkin(skinFilename)) {}

void SingleSkinGameActor::draw() {
	DrawSprite(
		this->skin,
		this->position.x, this->position.y,
		this->size.x, this->size.y,
		this->angle,
		0xffffffff
	);
}

bool SingleSkinGameActor::hit(const SingleSkinGameActor & actor) const {
	return this->getDistanceTo(actor) <= 0;
}

float SingleSkinGameActor::getDistanceTo(const SingleSkinGameActor & actor) const {
	Vector<int> offset = this->getOffsetTo(actor);
	return offset.length() - this->getRadius() - actor.getRadius();
}

Vector<int> SingleSkinGameActor::getOffsetTo(const SingleSkinGameActor & actor) const {
	return actor.position - this->position;
}

unsigned int SingleSkinGameActor::getRadius() const {
	return std::max(this->size.x, this->size.y);
}

