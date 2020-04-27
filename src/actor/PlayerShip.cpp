#define _USE_MATH_DEFINES
#include <cmath>

#include "lib/leetlib.h"

#include "PlayerShip.h"
#include "game/SpaceBattle.h"
#include "actor/Bullet.h"
#include "actor/Explosion.h"
#include "util/SkinLoader.h"
#include "util/JukeBox.h"

#define SHIP_SKIN_FILENAME			"gfx/Big Invader.png"
#define SHIP_SIZE					50
#define SHIP_STEP_SIZE				7

#define SHIP_GUN_LOADING_INTERVAL	15
#define SHIP_GUN_SHOT_DIRECTION		0,-4

PlayerShip::PlayerShip() :
	SkinGameActor(), gun(SHIP_GUN_LOADING_INTERVAL)
{
	this->setSize(SHIP_SIZE);
	this->stepSize = SHIP_STEP_SIZE;
}

void * PlayerShip::getSkin() const {
	return SkinLoader::getSkin(SHIP_SKIN_FILENAME);
}

void PlayerShip::tick(GameEngine & engine) {
	if (IsKeyDown(VK_LEFT) && this->canMoveLeft())
		this->moveLeft();
	if (IsKeyDown(VK_RIGHT) && this->canMoveRight())
		this->moveRight();
	unsigned int time = engine.getTime();
	this->rotate(time);
	this->gun.tick((SpaceBattle&)engine);
}

void PlayerShip::rotate(unsigned int time) {
	this->setAngle(M_PI + sin(time*0.1f)*0.1f);
}

bool PlayerShip::canMoveLeft() {
	int bound = this->getLeftBound();
	return bound - (int)stepSize >= this->positionRange[0];
}

bool PlayerShip::canMoveRight() {
	int bound = this->getRightBound();
	return bound + stepSize <= this->positionRange[1];
}

class ShipExplosion : public Explosion {
public:
	ShipExplosion(const PlayerShip & ship) :
		Explosion(ship) {}
	virtual void check(GameEngine & engine);
};

void ShipExplosion::check(GameEngine & engine) {
	if (!this->isOver())
		return;
	SpaceBattle & battle = (SpaceBattle&)engine;
	battle.remove(this);
	battle.nextShip();
}
	
void PlayerShip::explode(SpaceBattle & battle) {
	ShipExplosion * explosion = new ShipExplosion(*this);
	battle.removeShip(this);
	battle.add(explosion);
	JukeBox::playerExplosion();
}

void Gun::tick(SpaceBattle & battle) {
	this->doLoading();
}

void Gun::check(SpaceBattle & battle, PlayerShip & ship) {
	if (!IsKeyDown(VK_SPACE))
		this->setLoaded();
	else if (this->isLoaded())
		this->shoot(battle, ship);
}

void Gun::shoot(SpaceBattle & battle, PlayerShip & ship) {
	Bullet * bullet = this->createBullet(ship);
	battle.add(bullet);
	JukeBox::shoot();
	this->restartLoading();
}

Bullet * Gun::createBullet(const PlayerShip & ship) {
	Bullet * bullet = new Bullet();
	const Vector<int> & position = ship.getPosition();
	bullet->setPosition(position);
	bullet->setSpeed(SHIP_GUN_SHOT_DIRECTION);
	return bullet;
}
