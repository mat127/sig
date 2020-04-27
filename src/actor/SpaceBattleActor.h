#pragma once
#include "game/GameActor.h"

enum SpaceBattleActorType {
	ALIEN,
	SHIP,
	BULLET
};

class SpaceBattleActor : public GameActor {
public:
	virtual bool isA(const SpaceBattleActorType & type) {
		return false;
	}
};