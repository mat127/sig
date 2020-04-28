#include "lib/leetlib.h"

#include "JukeBox.h"

void * JukeBox::_intro;
void * JukeBox::_gameOver;
void * JukeBox::_newHighScore;

void * JukeBox::_highlyLoaded;
void * JukeBox::_shoot;
void * JukeBox::_playerExplosion;
void * JukeBox::_alienExplosion;

void JukeBox::initialize() {
	JukeBox::_intro = LoadSnd("sfx/intro.wav", true);
	JukeBox::_gameOver = LoadSnd("sfx/game-over.wav", true);
	JukeBox::_newHighScore = LoadSnd("sfx/new-high-score.wav", true);

	JukeBox::_highlyLoaded = LoadSnd("sfx/highly-loaded.wav");
	JukeBox::_shoot = LoadSnd("sfx/shoot.wav");
	JukeBox::_playerExplosion = LoadSnd("sfx/ship-explosion.wav");
	JukeBox::_alienExplosion = LoadSnd("sfx/invader-explosion.wav");
}

void JukeBox::stop(int handle) {
	StopSnd(handle);
}

int JukeBox::intro() {
	return PlaySnd(JukeBox::_intro);
}

int JukeBox::gameOver() {
	return PlaySnd(JukeBox::_gameOver);
}

int JukeBox::newHighScore() {
	return PlaySnd(JukeBox::_newHighScore);
}

int JukeBox::highlyLoaded() {
	return PlaySnd(JukeBox::_highlyLoaded);
}

int JukeBox::shoot() {
	return PlaySnd(JukeBox::_shoot);
}

int JukeBox::playerExplosion() {
	return PlaySnd(JukeBox::_playerExplosion);
}

int JukeBox::alienExplosion() {
	return PlaySnd(JukeBox::_alienExplosion);
}
