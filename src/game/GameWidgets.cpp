#include "GameWidgets.h"
#include "SpaceInvadersGame.h"
#include "GameStats.h"

GameWidgets::GameWidgets(const SpaceInvadersGame & game)
	: game(game)
{
	this->score.origin.set(600, 20);
	this->lives.origin.set(400, 20);
}

void GameWidgets::draw() {
	const GameStats & stats = this->game.getStats();
	this->drawScore(stats);
	this->drawLives(stats);
}

void GameWidgets::drawScore(const GameStats & stats) {
	char buffer[64];
	snprintf(buffer, sizeof(buffer), "score %06u", stats.score);
	this->score.draw(buffer);
}

void GameWidgets::drawLives(const GameStats & stats) {
	char buffer[64];
	snprintf(buffer, sizeof(buffer), "lives %1u", stats.lives);
	this->lives.draw(buffer);
}
