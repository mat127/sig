#include "game/SpaceInvadersConfig.h"
#include "Bullet.h"
#include "game/SpaceBattle.h"
#include "actor/Alien.h"
#include "util/SkinLoader.h"

Bullet::Bullet() :
	SkinGameActor()
{
	this->setSize(SIG_BULLET_SIZE);
}

void * Bullet::getSkin() const {
	return SkinLoader::getSkin(SIG_BULLET_SKIN_FILENAME);
}

void Bullet::tick(GameEngine & engine) {
	this->move(this->speed);
	this->rotate(SIG_BULLET_ROTATION_SPEED);
}

void Bullet::check(GameEngine & engine) {
	SpaceBattle & battle = (SpaceBattle&)engine;
	if (this->missed()) {
		battle.remove(this);
		return;
	}
	for (GameActor * actor : battle.getActors()) {
		Alien * alien = Alien::cast(actor);
		if(alien == nullptr) // can kill only an alien
			continue;
		if (this->hit(*alien)) {
			this->kill(battle, *alien);
			return;
		}
	}
}

void Bullet::kill(SpaceBattle & battle, Alien & alien) {
	alien.explode(battle);
	if(battle.remove(this)) // maybe hit by another bullet already?
		battle.killed(alien);
}
