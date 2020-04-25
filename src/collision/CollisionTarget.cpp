#include "CollisionTarget.h"

bool CollisionTarget::collide(const CollisionTarget & other) const {
	auto shape1 = this->getShape();
	auto shape2 = other.getShape();
	return shape1.intersects(shape2);
}
