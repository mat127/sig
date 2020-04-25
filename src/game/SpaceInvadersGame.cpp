#include <iostream>

#include "lib/leetlib.h"

#include "SpaceInvadersGame.h"

SpaceInvadersGame::SpaceInvadersGame() :
	ship(400),
	aliens(50),
	time(0u),
	widgets(*this)
{
	ship.setPositionRange(0, SCREEN_X);
}

void SpaceInvadersGame::run() {
	while (!WantQuit()
		&& !IsKeyDown(VK_ESCAPE)
		&& !this->isOver()
	) {
		this->tick();
		this->checkCollisions();
		this->draw();
	}
}

void SpaceInvadersGame::tick() {
	this->time++;
	this->ship.tick(this->time);
	this->aliens.tick(this->time);
}

void SpaceInvadersGame::draw() {
	this->ship.draw();
	this->aliens.draw();
	this->widgets.draw();
	Flip();
}

void SpaceInvadersGame::checkCollisions() {
	this->checkAlienBulletHits();
	this->checkShipAlienCollisions();
}

void SpaceInvadersGame::checkAlienBulletHits() {
	ShipGun & gun = this->ship.getGun();
	std::forward_list<Alien*> dead;
	for (auto it = this->aliens.begin(); it != this->aliens.end(); it++) {
		if (gun.hit(**it))
			dead.push_front(*it);
	}
	this->killed(dead);
}

void SpaceInvadersGame::killed(const std::forward_list<Alien*> & aliens) {
	for (auto it = aliens.begin(); it != aliens.end(); it++) {
		this->stats.killed(**it);
		this->aliens.remove(*it);
	}
}

void SpaceInvadersGame::checkShipAlienCollisions() {
	for (auto it = this->aliens.begin(); it != this->aliens.end(); it++) {
		if ((*it)->hit(this->ship)) {
			this->playerDead();
			this->aliens.remove(*it);
			return;
		}
	}
}