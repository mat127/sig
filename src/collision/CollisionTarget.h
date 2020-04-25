#pragma once
#include "CollisionTargetShape.h"

class CollisionTarget {
public:
	bool CollisionTarget::collide(const CollisionTarget & other) const;
	virtual CollisionTargetShape getShape() const = 0;
};
