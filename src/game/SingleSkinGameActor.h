#pragma once
#include <algorithm>

#include "GameActor.h"
#include "util/Vector.h"

class SingleSkinGameActor : public GameActor {
protected:
	void * skin;
	Vector<int> position;
	Vector<unsigned int> size;
	float angle;

public:
	SingleSkinGameActor(void * skin);
	SingleSkinGameActor(const char * skinFilename);

	const Vector<int> & getPosition() const {
		return this->position;
	}

	void setPosition(const int x, const int y) {
		this->position.set(x,y);
	}

	void setPosition(const Vector<int> & position) {
		this->position = position;
	}

	void move(const int dx, const int dy) {
		this->position += Vector<int>(dx, dy);
	}

	void setSize(const unsigned int dx, const unsigned int dy) {
		this->size.set(dx, dy);
	}

	void setSize(const unsigned int size) {
		this->setSize(size, size);
	}

	inline void setAngle(const float angle) {
		this->angle = angle;
	}

	inline void rotate(float angle) {
		this->angle += angle;
	}

	inline int getLeftBound() { return this->position.x - this->size.x; }
	inline int getRightBound() { return this->position.x + this->size.x; }

	float getDistanceTo(const SingleSkinGameActor & actor) const;
	Vector<int> getOffsetTo(const SingleSkinGameActor & actor) const;
	unsigned int getRadius() const;

	virtual void draw();

	bool hit(const SingleSkinGameActor & actor) const;
};
