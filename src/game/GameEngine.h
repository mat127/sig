#pragma once
#include <forward_list>

#include "GameActor.h"

struct AtomicStateChange {
	std::forward_list<GameActor*> toAdd;
	std::forward_list<GameActor*> toRemove;
	void add(GameActor * actor) {
		toAdd.push_front(actor);
	}
	void remove(GameActor * actor) {
		toRemove.push_front(actor);
	}
	void clear() {
		toAdd.clear();
		toRemove.clear();
	}
};

class GameEngine {
private:
	unsigned int time;
	AtomicStateChange pending;

protected:
	std::forward_list<GameActor*> actors;

	void tick();
	virtual void check();
	void applyChanges();
	virtual void draw();

	virtual bool isOver() const = 0;

public:
	GameEngine() : actors(), time(0u) {}
	~GameEngine();

	void add(GameActor * actor) {
		this->pending.add(actor);
	}

	void remove(GameActor * actor) {
		this->pending.remove(actor);
	}

	unsigned int getTime() const {
		return this->time;
	}

	const std::forward_list<GameActor*> getActors() const {
		return actors;
	}

	bool run();
};

