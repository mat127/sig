#pragma once
#include "GameActor.h"
#include "lib/leetlib.h"

class PlayerShip :
	public GameActor
{
private:
	unsigned int position;
	float angle;
	unsigned int positionRange[2];

	static void * skin;
	static const unsigned int verticalPosition;
	static const unsigned int size[];
	static const int stepSize;

public:
	PlayerShip(unsigned int position) : position(position) {}

	static void loadSkin();

	inline void setPositionRange(const unsigned int min, const unsigned int max) {
		this->positionRange[0] = min;
		this->positionRange[1] = max;
	}

	virtual void draw();
	virtual void tick(unsigned int time);

	bool canMoveLeft() {
		return this->position >= PlayerShip::positionRange[0] + PlayerShip::size[0] + PlayerShip::stepSize;
	}
	bool canMoveRight() {
		return this->position <= PlayerShip::positionRange[1] - PlayerShip::size[0] - PlayerShip::stepSize;
	}
	void moveLeft() {
		this->position -= stepSize;
	}
	void moveRight() {
		this->position += stepSize;
	}
	inline void setAngle(const double angle) {
		this->angle = angle;
	}
};
