#pragma once
#include <forward_list>

#include "GameStats.h"
#include "actor/PlayerShip.h"
#include "actor/AlienFleet.h"
#include "SpaceBattleWidgets.h"

class SpaceBattle {
private:
	unsigned int time;
	PlayerShip ship;
	AlienFleet aliens;

	SpaceBattleWidgets widgets;
	GameStats stats;

	void tick();
	void draw();

	void checkCollisions();
	void checkAlienBulletHits();
	void checkShipAlienCollisions();

	void killed(const std::forward_list<Alien*> & aliens);

	void playerDead() { this->stats.playerDied(); }
	bool isOver() const { return !this->stats.isPlayerAlive(); }

public:
	const HighScore & highScore;

	SpaceBattle(const HighScore & highScore);
	bool run();

	const GameStats & getStats() const { return this->stats; }
};

