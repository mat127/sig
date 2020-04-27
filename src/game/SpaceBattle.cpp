#include <algorithm>

#include "lib/leetlib.h"

#include "SpaceBattle.h"
#include "actor/PlayerShip.h"
#include "actor/Alien.h"
#include "util/JukeBox.h"

#define FLEET_ALIEN_COUNT	50

SpaceBattle::SpaceBattle(const HighScore & highScore) :
	GameEngine(),
	highScore(highScore),
	widgets(stats, highScore)
{
	this->ship = this->createShip();
	this->createAlienFleet();
}

PlayerShip * SpaceBattle::createShip() {
	PlayerShip * ship = new PlayerShip();
	ship->setPositionRange(0, SCREEN_X);
	ship->setPosition(SCREEN_X/2, 550);
	this->setShip(ship);
	return ship;
}

void SpaceBattle::createAlienFleet() {
	for (unsigned int i = 0; i < FLEET_ALIEN_COUNT; i++) {
		Alien * alien = new Alien(i);
		this->add(alien);
	}
}

void SpaceBattle::setShip(PlayerShip * ship) {
	this->ship = ship;
	this->add(ship);
}

void SpaceBattle::removeShip(PlayerShip * ship) {
	this->remove(ship);
	this->ship = nullptr;
}

void SpaceBattle::nextShip() {
	this->stats.playerDied();
	if (!this->isOver())
  	    this->createShip();
}

bool SpaceBattle::areAllAliensDead() const {
	return std::find_if(this->actors.begin(), this->actors.end(),
		[](GameActor * a) { return Alien::cast(a) != nullptr; }
	) == this->actors.end();
}

void SpaceBattle::checkAlienCount() {
	if (this->areAllAliensDead())
		this->createAlienFleet();
}

void SpaceBattle::draw() {
	this->widgets.draw();
	GameEngine::draw();
}