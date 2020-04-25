#include "lib/leetlib.h"

#include "SpaceInvadersGame.h"

SpaceInvadersGame::SpaceInvadersGame() :
	ship(400),
	aliens(50),
	time(0u)
{
	ship.setPositionRange(0, SCREEN_X);
}

void SpaceInvadersGame::run() {
	while (!WantQuit() && !IsKeyDown(VK_ESCAPE)) {
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
	for (auto it = dead.begin(); it != dead.end(); it++) {
		this->aliens.remove(*it);
	}
}

void SpaceInvadersGame::checkShipAlienCollisions() {


}
