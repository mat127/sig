#pragma once
#include "GameActor.h"

class SingleSkinGameActor : public GameActor {
protected:
	void * skin;
	int position[2];
	unsigned int size[2];
	float angle;

public:
	SingleSkinGameActor(void * skin);
	SingleSkinGameActor(const char * skinFilename);

	inline const int * getPosition() const {
		return this->position;
	}

	inline void setPosition(const int x, const int y) {
		this->position[0] = x;
		this->position[1] = y;
	}

	inline void setPosition(const int position[]) {
		this->position[0] = position[0];
		this->position[1] = position[1];
	}

	inline void move(const int dx, const int dy) {
		this->position[0] += dx;
		this->position[1] += dy;
	}

	inline void setSize(unsigned int dx, unsigned int dy) {
		this->size[0] = dx;
		this->size[1] = dy;
	}

	inline void setSize(unsigned int size) {
		this->size[0] = size;
		this->size[1] = size;
	}

	inline void setAngle(float angle) {
		this->angle = angle;
	}

	inline void rotate(float angle) {
		this->angle += angle;
	}

	inline int getLeftBound() { return this->position[0] - this->size[0]; }
	inline int getRightBound() { return this->position[0] + this->size[0]; }

	virtual void draw();
};

