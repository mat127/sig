#pragma once
#include "Drawable.h"

class GameEngine;

class GameActor : public Drawable {
public:
	virtual void tick(GameEngine & engine) {
		// idle
	}
	virtual void check(GameEngine & engine) {
		// nothing to check by default
	}
};

