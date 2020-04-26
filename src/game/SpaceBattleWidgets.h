#pragma once
#include "GameObject.h"
#include "widget/TextWidget.h"

class SpaceBattle;
struct GameStats;

class SpaceBattleWidgets : public GameObject {
private:
	const SpaceBattle & battle;

	TextWidget score;
	TextWidget lives;

	void drawScore(const GameStats & stats);
	void drawLives(const GameStats & stats);

public:
	SpaceBattleWidgets(const SpaceBattle & game);
	virtual void draw();
};

