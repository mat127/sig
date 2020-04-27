#pragma once
#include "Drawable.h"
#include "widget/TextWidget.h"

class SpaceBattle;
struct GameStats;
struct HighScore;

class SpaceBattleWidgets : public Drawable {
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

