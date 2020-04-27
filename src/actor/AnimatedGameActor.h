#pragma once
#include "SkinGameActor.h"

#define ANIMATED_ACTOR_FRAME_DURATION 10

class SpaceBattle;

class AnimatedGameActor : public SkinGameActor {
protected:
	unsigned int frameCount;
	unsigned int frameDuration;
	unsigned int counter;

	unsigned int getFrameIndex() const {
		return this->counter / frameDuration;
	}

	virtual void * getSkin(unsigned int frameIndex) const = 0;
	virtual void * getSkin() const {
		return this->getSkin(this->getFrameIndex());
	}

public:
	AnimatedGameActor(
		unsigned int frameCount,
		unsigned int frameDuration = ANIMATED_ACTOR_FRAME_DURATION
	) : frameCount(frameCount), frameDuration(frameDuration), counter(0) {}

	bool isOver() const {
		return this->getFrameIndex() >= this->frameCount;
	}
	virtual void tick(GameEngine & engine) {
		this->counter++;
	}
	virtual void draw();
};

