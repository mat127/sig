#pragma once
#include "lib/leetlib.h"

#include "SkinGameActor.h"
#include "util/Vector.h"

class Bullet;
class PlayerShip;
class SpaceBattle;

class Gun {
private:
	static Vector<int> bulletDirections[];

	PlayerShip & ship;
	unsigned int loadingLevel;
	unsigned int highLoadingLevel;

	void doLoading();
	bool isLoaded() const {
		return this->loadingLevel > 0;
	}
	bool isHighlyLoaded() const {
		return this->loadingLevel >= this->highLoadingLevel;
	}
	void restartLoading();

	void shoot(SpaceBattle & battle);
	void shootSingle(SpaceBattle & battle);
	void shootSpray(SpaceBattle & battle);
	Bullet * createBullet(const Vector<int> & direction);

public:
	Gun(PlayerShip & ship, unsigned int highLoadingLevel);
	void tick(SpaceBattle & battle);
};

class PlayerShip : public SkinGameActor {
private:
	int positionRange[2];
	int stepSize;
	Gun gun;

protected:
	virtual void * getSkin() const;

public:
	PlayerShip();

	virtual bool isA(const SpaceBattleActorType & type) {
		return type == SHIP;
	}

	inline void setPositionRange(const int min, const int max) {
		this->positionRange[0] = min;
		this->positionRange[1] = max;
	}

	virtual void tick(GameEngine & engine);

	bool canMoveLeft();
	bool canMoveRight();
	inline void moveLeft() {
		this->move(-stepSize,0);
	}
	inline void moveRight() {
		this->move(stepSize, 0);
	}

	void rotate(unsigned int time);

	void explode(SpaceBattle & battle);
};
