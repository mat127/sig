#include "lib/leetlib.h"

#include "JukeBox.h"

void * JukeBox::_intro;

void * JukeBox::_shoot;
void * JukeBox::_playerExplosion;
void * JukeBox::_alienExplosion;

void JukeBox::initialize() {
	JukeBox::_intro = LoadSnd("sfx/intro.wav", true);
	JukeBox::_shoot = LoadSnd("sfx/shoot.wav");
	JukeBox::_playerExplosion = LoadSnd("sfx/explosion.wav");
	JukeBox::_alienExplosion = LoadSnd("sfx/invaderkilled.wav");
}

void JukeBox::stop(int handle) {
	StopSnd(handle);
}

int JukeBox::intro() {
	return PlaySnd(JukeBox::_intro);
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
