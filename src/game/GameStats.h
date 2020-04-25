#pragma once
#include "actor/Alien.h"

struct GameStats {
	unsigned int lives;
	unsigned int score;
	GameStats() : lives(3), score(0) {}
	void playerDied() {
		this->lives--;
	}
	bool isPlayerAlive() const {
		return this->lives > 0;
	}
	void killed(const Alien & alien) {
		this->score += alien.getScore();
	}
	void reset() {
		this->lives = 3;
		this->score = 0;
	}
};

