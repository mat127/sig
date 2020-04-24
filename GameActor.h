#pragma once
#include "GameObject.h"

class GameActor : public GameObject {
public:
	virtual void tick(unsigned int time) = 0;
};

