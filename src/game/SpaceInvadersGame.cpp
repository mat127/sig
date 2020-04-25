#include "lib/leetlib.h"

#include "SpaceInvadersGame.h"
#include "widget/WidgetScreen.h"

SpaceInvadersGame::SpaceInvadersGame() :
	ship(400),
	aliens(50),
	time(0u),
	widgets(*this)
{
	ship.setPositionRange(0, SCREEN_X);
}

void SpaceInvadersGame::run() {
	if(!this->intro())
		return;
	do {
		if(!this->battle())
			break;
	} while (this->playAgain());
}

bool SpaceInvadersGame::intro() {
	WidgetScreen screen;

	TextWidget title(200, 200, 32);
	title.text = "space invaders";
	screen.add(&title);

	TextWidget start(120, 400, 24);
	start.text = "press space bar to start";
	screen.add(&start);

	return screen.show(VK_SPACE);
}

bool SpaceInvadersGame::battle() {
	while(!this->isOver()) {
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

bool SpaceInvadersGame::playAgain() {
	WidgetScreen screen;

	TextWidget gameOver(140, 200, 64);
	gameOver.text = "game over";
	screen.add(&gameOver);

	TextWidget score(220, 350, 24);
	score.format("your score %06u", this->stats.score);
	screen.add(&score);

	if (!screen.show(VK_SPACE))
		return false;

	this->stats.reset();
	return true;
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