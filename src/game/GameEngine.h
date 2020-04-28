#pragma once
#include <forward_list>

#include "GameActor.h"

struct AtomicStateChange {
	std::forward_list<GameActor*> toAdd;
	std::forward_list<GameActor*> toRemove;
	void add(GameActor * actor) {
		toAdd.push_front(actor);
	}
	bool remove(GameActor * actor);
	bool isRemoved(const GameActor * actor) const;
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

	virtual void tick();
	virtual void check();
	virtual void applyChanges();
	virtual void draw();

	virtual bool isOver() const = 0;

public:
	GameEngine() : actors(), time(0u) {}
	~GameEngine();

	void add(GameActor * actor) {
		this->pending.add(actor);
	}

	bool remove(GameActor * actor) {
		return this->pending.remove(actor);
	}

	unsigned int getTime() const {
		return this->time;
	}

	const std::forward_list<GameActor*> getActors() const {
		return actors;
	}

	bool run();
};

