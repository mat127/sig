#include <cmath>

#include "CollisionTargetShape.h"

CollisionTargetShape::CollisionTargetShape(
	float originX, float originY,
	float radius
) :
	origin(2), radius(radius)
{
	this->origin[0] = originX;
	this->origin[1] = originY;
}

bool CollisionTargetShape::intersects(const CollisionTargetShape & other) const {
	float distance = this->getOriginDistance(other);
	return distance <= (this->radius + other.radius);
}

float CollisionTargetShape::getOriginDistance(const CollisionTargetShape & other) const {
	auto offset = this->getOffsetTo(other);
	return sqrtf(offset[0] * offset[0] + offset[1] * offset[1]);
}
