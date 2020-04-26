#include "lib/leetlib.h"

#include "JukeBox.h"

void * JukeBox::_shoot;
void * JukeBox::_playerExplosion;
void * JukeBox::_alienExplosion;

void JukeBox::initialize() {
	JukeBox::_shoot = LoadSnd("sfx/shoot.wav");
	JukeBox::_playerExplosion = LoadSnd("sfx/explosion.wav");
	JukeBox::_alienExplosion = LoadSnd("sfx/invaderkilled.wav");
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
