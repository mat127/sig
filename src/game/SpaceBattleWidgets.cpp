#include "SpaceBattleWidgets.h"
#include "SpaceBattle.h"
#include "GameStats.h"

SpaceBattleWidgets::SpaceBattleWidgets(const SpaceBattle & battle)
	: battle(battle)
{
	this->score.origin.set(500, 20);
	this->lives.origin.set(300, 20);
}

void SpaceBattleWidgets::draw() {
	const GameStats & stats = this->battle.getStats();
	this->drawScore(stats);
	this->drawLives(stats);
}

void SpaceBattleWidgets::drawScore(const GameStats & stats) {
	char buffer[64];
	snprintf(buffer, sizeof(buffer), "score %06u", stats.score);
	this->score.draw(buffer);
}

void SpaceBattleWidgets::drawLives(const GameStats & stats) {
	char buffer[64];
	snprintf(buffer, sizeof(buffer), "lives %1u", stats.lives);
	this->lives.draw(buffer);
}
