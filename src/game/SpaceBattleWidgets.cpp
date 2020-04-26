#include "lib/leetlib.h"

#include "SpaceBattleWidgets.h"
#include "SpaceBattle.h"
#include "GameStats.h"
#include "HighScore.h"

SpaceBattleWidgets::SpaceBattleWidgets(
	const GameStats & stats,
	const HighScore & highScore
) : stats(stats), highScore(highScore)
{
	this->scoreWidget.origin.set(550, 20);
	this->scoreWidget.spacingFactor = 1.1f;

	this->livesWidget.origin.set(350, 20);
	this->livesWidget.spacingFactor = 1.f;

	this->highScoreWidget.origin.set(10, 20);
	this->highScoreWidget.spacingFactor = 1.1f;
}

SpaceBattleWidgets::SpaceBattleWidgets(const SpaceBattle & battle) :
  SpaceBattleWidgets(battle.getStats(), battle.highScore) {}

void SpaceBattleWidgets::draw() {
	this->scoreWidget.draw("score %06u", stats.score);
	this->livesWidget.draw("lives %1u", stats.lives);
	this->highScoreWidget.draw("high score %06u", highScore.get());
}
