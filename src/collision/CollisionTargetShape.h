#pragma once
#include <valarray>

struct CollisionTargetShape {
	std::valarray<float> origin;
	float radius;

	CollisionTargetShape(float originX, float originY, float radius = 0.f);
	CollisionTargetShape() : CollisionTargetShape(0, 0) {}
	CollisionTargetShape(const CollisionTargetShape & src)
		: origin(src.origin), radius(src.radius) {}

	bool intersects(const CollisionTargetShape & other) const;

	std::valarray<float> getOffsetTo(const CollisionTargetShape & other) const {
		return other.origin - this->origin;
	}
	float getOriginDistance(const CollisionTargetShape & other) const;
};

