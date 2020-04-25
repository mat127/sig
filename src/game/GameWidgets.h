#pragma once
#include "GameObject.h"
#include "widget/TextWidget.h"

class SpaceInvadersGame;
struct GameStats;

class GameWidgets : public GameObject {
private:
	const SpaceInvadersGame & game;

	TextWidget score;
	TextWidget lives;

	void drawScore(const GameStats & stats);
	void drawLives(const GameStats & stats);

public:
	GameWidgets(const SpaceInvadersGame & game);
	virtual void draw();
};

