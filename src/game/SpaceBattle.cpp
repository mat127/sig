#include "lib/leetlib.h"

#include "SpaceBattle.h"
#include "util/JukeBox.h"

SpaceBattle::SpaceBattle(const HighScore & highScore) :
	ship(400),
	aliens(50),
	time(0u),
	highScore(highScore),
	widgets(stats, highScore)
{
	ship.setPositionRange(0, SCREEN_X);
}

bool SpaceBattle::run() {
	while (!this->isOver()) {
		if (WantQuit()
			|| IsKeyDown(VK_ESCAPE)
			)
			return false;
		this->tick();
		this->checkCollisions();
		this->draw();
	}
	return true;
}

void SpaceBattle::tick() {
	this->time++;
	this->ship.tick(this->time);
	this->aliens.tick(this->time);
}

void SpaceBattle::draw() {
	this->ship.draw();
	this->aliens.draw();
	this->widgets.draw();
	Flip();
}

void SpaceBattle::checkCollisions() {
	this->checkAlienBulletHits();
	this->checkShipAlienCollisions();
}

void SpaceBattle::checkAlienBulletHits() {
	ShipGun & gun = this->ship.getGun();
	std::forward_list<Alien*> dead;
	for(Alien * alien : aliens) {
		if (gun.hit(*alien))
			dead.push_front(alien);
	}
	this->killed(dead);
}

void SpaceBattle::killed(const std::forward_list<Alien*> & aliens) {
	for (auto alien: aliens) {
		JukeBox::alienExplosion();
		this->stats.killed(*alien);
		this->aliens.remove(alien);
	}
}

void SpaceBattle::checkShipAlienCollisions() {
	for (auto alien: this->aliens) {
		if (alien->hit(this->ship)) {
			this->playerDead();
			this->aliens.remove(alien);
			return;
		}
	}
}

void SpaceBattle::playerDead() {
	JukeBox::playerExplosion();
	this->stats.playerDied();
}