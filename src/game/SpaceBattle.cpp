#include "lib/leetlib.h"

#include "SpaceBattle.h"

SpaceBattle::SpaceBattle() :
	ship(400),
	aliens(50),
	time(0u),
	widgets(*this)
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
	for (auto it = this->aliens.begin(); it != this->aliens.end(); it++) {
		if (gun.hit(**it))
			dead.push_front(*it);
	}
	this->killed(dead);
}

void SpaceBattle::killed(const std::forward_list<Alien*> & aliens) {
	for (auto it = aliens.begin(); it != aliens.end(); it++) {
		this->stats.killed(**it);
		this->aliens.remove(*it);
	}
}

void SpaceBattle::checkShipAlienCollisions() {
	for (auto it = this->aliens.begin(); it != this->aliens.end(); it++) {
		if ((*it)->hit(this->ship)) {
			this->playerDead();
			this->aliens.remove(*it);
			return;
		}
	}
}