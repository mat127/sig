#include "lib/leetlib.h"

#include "SpaceInvadersGame.h"
#include "SpaceBattle.h"
#include "util/JukeBox.h"
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
	bool show();
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

bool Intro::show() {
	int snd = JukeBox::intro();
	bool result = WidgetScreen::show();
	JukeBox::stop(snd);
	return result;
}

class GameOver : public WidgetScreen {
private:
	const GameStats & stats;
	HighScore & highScore;

	TextWidget gameOver;
	TextWidget score;
	TextWidget whatNext;

	int soundLoop;

	void newHighScore();
	void normalScore();

public:
	GameOver(const GameStats & stats, HighScore & highScore);
	bool show();
};

GameOver::GameOver(const GameStats & stats, HighScore & highScore) :
	stats(stats), highScore(highScore)
{
	gameOver.text = "game over";
	gameOver.charSize = 48;
	gameOver.setCenter(SCREEN_X/2, 200);
	this->add(&gameOver);

	score.charSize = 16;
	this->add(&score);

	whatNext.text = "press space bar for a new game";
	whatNext.charSize = 16;
	whatNext.setCenter(SCREEN_X / 2, 450);
	this->add(&whatNext);
}

bool GameOver::show() {
	if (this->highScore.adjust(this->stats.score))
		this->newHighScore();
	else
		this->normalScore();
	bool result = WidgetScreen::show();
	JukeBox::stop(this->soundLoop);
	return result;
}

void GameOver::newHighScore() {
	this->score.format("congrats new high score %06u", this->highScore.value);
	score.setCenter(SCREEN_X / 2, 350);
	this->soundLoop = JukeBox::newHighScore();
}

void GameOver::normalScore() {
	score.format("your score %06u", this->stats.score);
	score.setCenter(SCREEN_X / 2, 350);
	this->soundLoop = JukeBox::gameOver();
}

void SpaceInvadersGame::run() {
	JukeBox::initialize();

	if (!Intro().show())
		return;

	while(true) {
		SpaceBattle battle(this->highScore);
		if (!battle.run())
			break;

		GameOver gameOver(battle.getStats(), this->highScore);
		if (!gameOver.show())
			break;
	}
}
