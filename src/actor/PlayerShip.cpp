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
#define SHIP_NORMAL_SIZE			30
#define SHIP_STEP_SIZE				7

#define SHIP_GUN_LOADING_INTERVAL	15
#define SHIP_GUN_SHOT_DIRECTION		0,-4

Vector<int> Gun::bulletDirections[] = {
	Vector<int>(SHIP_GUN_SHOT_DIRECTION),
	Vector<int>(SHIP_GUN_SHOT_DIRECTION) + Vector<int>(-1,0),
	Vector<int>(SHIP_GUN_SHOT_DIRECTION) + Vector<int>(1,0)
};

#define SPRAY_BULLET_COUNT			3

PlayerShip::PlayerShip() :
	SkinGameActor(), gun(*this, SHIP_GUN_LOADING_INTERVAL)
{
	this->setSize(SHIP_NORMAL_SIZE);
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

Gun::Gun(PlayerShip & ship, unsigned int highLoadingLevel) :
	ship(ship), highLoadingLevel(highLoadingLevel)
{
	this->restartLoading();
}

void Gun::tick(SpaceBattle & battle) {
	if (IsKeyDown(VK_SPACE))
		this->doLoading();
	else if (this->isLoaded())
		this->shoot(battle);
}

void Gun::doLoading() {
	if (this->loadingLevel >= this->highLoadingLevel)
		return;
	else
		this->loadingLevel++;
	this->ship.setSize(SHIP_NORMAL_SIZE + this->loadingLevel);
	if (this->isHighlyLoaded())
		JukeBox::highlyLoaded();
}

void Gun::restartLoading() {
	this->loadingLevel = 0;
	this->ship.setSize(SHIP_NORMAL_SIZE);
}

void Gun::shoot(SpaceBattle & battle) {
	if (this->isHighlyLoaded())
		this->shootSpray(battle);
	else
		this->shootSingle(battle);
}

void Gun::shootSingle(SpaceBattle & battle) {
	Bullet * bullet = this->createBullet(bulletDirections[0]);
	battle.add(bullet);
	JukeBox::shoot();
	this->restartLoading();
}

void Gun::shootSpray(SpaceBattle & battle) {
	for (int i = 0; i < SPRAY_BULLET_COUNT; i++) {
		Bullet * bullet = this->createBullet(bulletDirections[i]);
		battle.add(bullet);
	}
	JukeBox::shoot();
	this->restartLoading();
}

Bullet * Gun::createBullet(const Vector<int> & direction) {
	Bullet * bullet = new Bullet();
	const Vector<int> & position = this->ship.getPosition();
	bullet->setPosition(position);
	bullet->setDirection(direction);
	return bullet;
}
