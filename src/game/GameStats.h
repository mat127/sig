#pragma once
#include "SpaceInvadersConfig.h"
#include "actor/Alien.h"

struct GameStats {
	unsigned int lives;
	unsigned int score;
	GameStats() {
		this->reset();
	}
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
		this->lives = SIG_PLAYER_LIVES_COUNT;
		this->score = 0;
	}
};

