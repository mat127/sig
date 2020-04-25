#pragma once
#include "lib/leetlib.h"

#include "game/SingleSkinGameActor.h"
#include "ShipGun.h"

class PlayerShip : public SingleSkinGameActor {
private:
	int positionRange[2];
	int stepSize;
	ShipGun gun;

public:
	PlayerShip(unsigned int position);

	inline void setPositionRange(const int min, const int max) {
		this->positionRange[0] = min;
		this->positionRange[1] = max;
	}

	virtual void tick(unsigned int time);
	virtual void draw();

	bool canMoveLeft();
	bool canMoveRight();
	inline void moveLeft() {
		this->move(-stepSize,0);
	}
	inline void moveRight() {
		this->move(stepSize, 0);
	}

	void rotate(unsigned int time);

	ShipGun & getGun() { return this->gun; }
};
