#include "lib/leetlib.h"

#include "SpaceInvadersGame.h"
#include "SpaceBattle.h"
#include "widget/WidgetScreen.h"

void Game() {
	SpaceInvadersGame().run();
}

class Intro : public WidgetScreen {
private:
	TextWidget space;
	TextWidget invaders;
	TextWidget start;
public:
	Intro();
};

Intro::Intro() {
	space.text = "space";
	space.charSize = 48;
	space.setCenter(SCREEN_X/2, 150);
	this->add(&space);

	invaders.text = "invaders";
	invaders.charSize = 48;
	invaders.setCenter(SCREEN_X / 2, 280);
	this->add(&invaders);

	start.text = "press space bar to start";
	start.charSize = 16;
	start.setCenter(SCREEN_X / 2, 500);
	this->add(&start);
}

class GameOver : public WidgetScreen {
private:
	const GameStats & stats;
	TextWidget gameOver;
	TextWidget score;
public:
	GameOver(const GameStats & stats);
	GameOver(const SpaceBattle & battle) : GameOver(battle.getStats()) {}
};

GameOver::GameOver(const GameStats & stats) :
	stats(stats)
{
	gameOver.text = "game over";
	gameOver.charSize = 48;
	gameOver.setCenter(SCREEN_X/2, 200);
	this->add(&gameOver);

	score.format("your score %06u", this->stats.score);
	score.charSize = 16;
	score.setCenter(SCREEN_X/2, 350);
	this->add(&score);
}

void SpaceInvadersGame::run() {
	if (!Intro().show())
		return;

	while(true) {
		SpaceBattle battle;
		if (!battle.run())
			break;

		GameOver gameOver(battle);
		if (!gameOver.show())
			break;
	}
}
