#define NOMINMAX // avoid windows.h max() definition
#include <algorithm>

#include "lib/leetlib.h"

#include "SkinGameActor.h"
#include "util/SkinLoader.h"

SkinGameActor::SkinGameActor() :
	position(0,0), size(0,0), angle(0.f) {}

void SkinGameActor::draw() {
	void * skin = this->getSkin();
	DrawSprite(
		skin,
		(float)this->position.x, (float)this->position.y,
		(float)this->size.x, (float)this->size.y,
		this->angle,
		0xffffffff
	);
}

bool SkinGameActor::hit(const SkinGameActor & actor) const {
	return this->getDistanceTo(actor) <= 0;
}

float SkinGameActor::getDistanceTo(const SkinGameActor & actor) const {
	Vector<int> offset = this->getOffsetTo(actor);
	return offset.length() - this->getRadius() - actor.getRadius();
}

Vector<int> SkinGameActor::getOffsetTo(const SkinGameActor & actor) const {
	return actor.position - this->position;
}

unsigned int SkinGameActor::getRadius() const {
	return std::max(this->size.x, this->size.y);
}

