#pragma once

#include "GameEngine.h"
#include "GameStats.h"
#include "actor/PlayerShip.h"
#include "SpaceBattleWidgets.h"

class SpaceBattle : public GameEngine {
private:
	PlayerShip * ship;

	SpaceBattleWidgets widgets;
	GameStats stats;

	PlayerShip * createShip();
	void createAlienFleet();

protected:
	virtual bool isOver() const {
		return !this->stats.isPlayerAlive();
	}
	virtual void draw();

public:
	const HighScore & highScore;

	SpaceBattle(const HighScore & highScore);

	PlayerShip * getShip() {
		return this->ship;
	}
	void setShip(PlayerShip * ship);
	void removeShip(PlayerShip * ship);
	void nextShip();

	void killed(const Alien & alien) {
		this->stats.killed(alien);
	}

	const GameStats & getStats() const {
		return this->stats;
	}
};

