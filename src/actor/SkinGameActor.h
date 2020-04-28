#pragma once
#include <algorithm>

#include "SpaceBattleActor.h"
#include "game/Drawable.h"
#include "util/Vector.h"

class SkinGameActor : public SpaceBattleActor {
protected:
	Vector<int> position;
	Vector<unsigned int> size;
	float angle;

	virtual void * getSkin() const = 0;

public:
	SkinGameActor();

	const Vector<int> & getPosition() const {
		return this->position;
	}

	void setPosition(const Vector<int> & position) {
		this->position = position;
	}

	void setPosition(const int x, const int y) {
		this->position.set(x,y);
	}

	const Vector<unsigned int> & getSize() const {
		return this->size;
	}

	void setSize(const Vector<unsigned int> & size) {
		this->size = size;
	}

	void setSize(const unsigned int dx, const unsigned int dy) {
		this->size.set(dx, dy);
	}

	void setSize(const unsigned int size) {
		this->setSize(size, size);
	}

	void move(const Vector<int> direction) {
		this->position += direction;
	}

	void move(const int dx, const int dy) {
		this->position += Vector<int>(dx, dy);
	}

	inline void setAngle(const float angle) {
		this->angle = angle;
	}

	inline void rotate(float angle) {
		this->angle += angle;
	}

	inline int getLeftBound() { return this->position.x - this->size.x; }
	inline int getRightBound() { return this->position.x + this->size.x; }

	float getDistanceTo(const SkinGameActor & actor) const;
	Vector<int> getOffsetTo(const SkinGameActor & actor) const;
	unsigned int getRadius() const;

	virtual void draw();

	bool hit(const SkinGameActor & actor) const;
};
