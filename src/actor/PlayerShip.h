#pragma once
#include "lib/leetlib.h"

#include "SkinGameActor.h"

class Bullet;
class PlayerShip;
class SpaceBattle;

class Gun {
private:
	int counter;
	int loadingInterval;

	void doLoading() {
		if (this->counter > 0)
			this->counter--;
	}
	bool isLoaded() const {
		return this->counter == 0;
	}
	void setLoaded() {
		this->counter = 0;
	}
	void restartLoading() {
		this->counter = this->loadingInterval;
	}

	void shoot(SpaceBattle & battle, PlayerShip & ship);
	Bullet * createBullet(const PlayerShip & ship);

public:
	Gun(int loadingInterval) :
		loadingInterval(loadingInterval) {}
	void tick(SpaceBattle & battle);
	void check(SpaceBattle & battle, PlayerShip & ship);
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
	virtual void check(GameEngine & engine) {
		this->gun.check((SpaceBattle&)engine, *this);
	}

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
