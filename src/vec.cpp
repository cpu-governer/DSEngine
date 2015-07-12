#include "vec.h"

Vector2::Vector2() { }
Vector2::Vector2(float _x, float _y): x(_x), y(_y) { }

AABBCoords AABB::coords() const
{
	AABBCoords ret { pos.x, pos.y, pos.x + dim.x, pos.y + dim.y };
	return ret;
}

bool AABB::intersects(const AABB& other) const
{
	AABBCoords r1 = coords();
	AABBCoords r2 = other.coords();

	if(r1.x1 < r2.x2 && r1.x2 > r2.x1 && r1.y1 < r2.y2 && r1.y2 > r2.y1) {
		return true;
	} else {
		return false;
	}
}