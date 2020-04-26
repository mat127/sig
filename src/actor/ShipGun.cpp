
#include "lib/leetlib.h"

#include "ShipGun.h"
#include "PlayerShip.h"
#include "util/SkinLoader.h"
#include "util/JukeBox.h"

ShipGun::~ShipGun() {
	for(Bullet * b: this->bullets)
		delete b;
}

void ShipGun::remove(Bullet * bullet) {
	this->bullets.remove(bullet);
	delete bullet;
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

void ShipGun::tickBullets(unsigned int time) {
	this->bullets.remove_if(
		[](Bullet * b) { return b->missed(); }
	);
	for(Bullet * b: this->bullets)
		b->tick(time);
}

void ShipGun::draw() {
	for (Bullet * b : this->bullets)
		b->draw();
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
	auto bullet = this->createBullet();
	JukeBox::shoot();
	this->loading.restart();
}

Bullet * ShipGun::createBullet() {
	Bullet * bullet = new Bullet();
	const Vector<int> & position = this->ship.getPosition();
	bullet->setPosition(position);
	this->bullets.push_front(bullet);
	return bullet;
}

bool ShipGun::hit(const SingleSkinGameActor & actor) {
	for(Bullet * b : this->bullets) {
		if(b->hit(actor)) {
			this->remove(b);
			return true;
		}
	}
	return false;
}