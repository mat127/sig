#pragma once
#include <forward_list>

#include "GameStats.h"
#include "actor/PlayerShip.h"
#include "actor/AlienFleet.h"
#include "GameWidgets.h"

class SpaceInvadersGame {
private:
	GameStats stats;

	unsigned int time;
	PlayerShip ship;
	AlienFleet aliens;

	GameWidgets widgets;

	void tick();
	void draw();

	void checkCollisions();
	void checkAlienBulletHits();
	void checkShipAlienCollisions();

	void killed(const std::forward_list<Alien*> & aliens);

	void playerDead() { this->stats.playerDied(); }
	bool isOver() const { return !this->stats.isPlayerAlive(); }

public:
	SpaceInvadersGame();
	void run();

	const GameStats & getStats() const { return this->stats; }
};

