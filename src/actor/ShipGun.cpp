#include "lib/leetlib.h"

#include "ShipGun.h"
#include "PlayerShip.h"
#include "util/SkinLoader.h"

ShipGun::~ShipGun() {
	for (auto it = this->bullets.begin(); it != this->bullets.end(); it++) {
		delete (*it);
	}
}

void ShipGun::tick(unsigned int time) {
	if (!IsKeyDown(VK_SPACE))
		this->setLoaded();
	else if (this->isLoaded())
		this->shoot();
	else
		this->doLoading();
	this->tickBullets(time);
}

static bool _bulletMissed(const Bullet * bullet) {
	return bullet->missed();
}

void ShipGun::tickBullets(unsigned int time) {
	this->bullets.remove_if(_bulletMissed);
	for (auto it = this->bullets.begin(); it != this->bullets.end(); it++) {
		(*it)->tick(time);
	}
}

void ShipGun::draw() {
	for (auto it = this->bullets.begin(); it != this->bullets.end(); it++) {
		(*it)->draw();
	}
}

inline void ShipGun::doLoading() {
	this->loading.doLoading();
}

inline void ShipGun::setLoaded() {
	this->loading.setLoaded();
}

inline bool ShipGun::isLoaded() {
	return this->loading.isLoaded();
}

void ShipGun::shoot() {
	auto bullet = new Bullet(SkinLoader::getSkin("gfx/bullet.png"));
	const int * position = this->ship.getPosition();
	bullet->setPosition(position);
	this->bullets.push_front(bullet);
	this->loading.restart();
}

