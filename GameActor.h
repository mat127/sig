#pragma once
#include "GameObject.h"
class GameActor :
	public GameObject
{
public:
	GameActor();
	~GameActor();
	virtual void tick(unsigned int time) = 0;
};

