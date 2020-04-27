#include "lib/leetlib.h"

#include "GameEngine.h"

GameEngine::~GameEngine() {
	for (auto actor : this->actors)
		delete actor;
}

bool GameEngine::run() {
	while (!this->isOver()) {
		if (WantQuit()
			|| IsKeyDown(VK_ESCAPE)
		)
			return false;
		this->tick();
		this->check();
		this->applyChanges();
		this->draw();
	}
	return true;
}

void GameEngine::tick() {
	this->time++;
	for (auto actor : this->actors)
		actor->tick(*this);
}

void GameEngine::draw() {
	for (auto actor : this->actors)
		actor->draw();
	Flip();
}

void GameEngine::check() {
	for (auto actor : this->actors)
		actor->check(*this);
}

void GameEngine::applyChanges() {
	for (GameActor * actor : this->pending.toRemove) {
		this->actors.remove(actor);
		delete actor;
	}
	for (GameActor * actor : this->pending.toAdd) {
		this->actors.push_front(actor);
	}
	this->pending.clear();
}
