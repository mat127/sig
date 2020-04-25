#pragma once
#include <forward_list>

#include "game/SingleSkinGameActor.h"
#include "Bullet.h"

class LoadingTimer {
private:
	int counter;
	int initialValue;
public:
	LoadingTimer(const int initialValue) {
		this->initialValue = initialValue;
		this->restart();
	}
	void doLoading() {
		if (this->counter > 0)
			this->counter--;
	}
	bool isLoaded() {
		return this->counter == 0;
	}
	void setLoaded() {
		this->counter = 0;
	}
	void restart() {
		this->counter = this->initialValue;
	}
};

class PlayerShip;

class ShipGun : public GameActor {
private:
	const PlayerShip & ship;
	std::forward_list<Bullet *> bullets;
	LoadingTimer loading;

	void doLoading();
	void setLoaded();
	bool isLoaded();

	void shoot();

	void tickBullets(unsigned int time);

public:
	ShipGun(const PlayerShip & ship) :
		ship(ship), bullets(), loading(15) {}
	~ShipGun();
	virtual void tick(unsigned int time);
	virtual void draw();
};

