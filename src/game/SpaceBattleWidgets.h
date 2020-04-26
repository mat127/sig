#pragma once
#include "GameObject.h"
#include "widget/TextWidget.h"

class SpaceBattle;
struct GameStats;
class HighScore;

class SpaceBattleWidgets : public GameObject {
private:
	const GameStats & stats;
	const HighScore & highScore;

	TextWidget scoreWidget;
	TextWidget livesWidget;
	TextWidget highScoreWidget;

public:
	SpaceBattleWidgets::SpaceBattleWidgets(const GameStats & stats, const HighScore & highScore);
	SpaceBattleWidgets(const SpaceBattle & game);
	virtual void draw();
};

