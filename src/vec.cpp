#include "vec.h"

Dimension::Dimension() { }
Dimension::Dimension(int _x, int _y): x(_x), y(_y) { }

Vector2::Vector2() { }
Vector2::Vector2(float _x, float _y): x(_x), y(_y) { }

Vector2& Vector2::operator=(const Vector2& other)
{
	if(this == &other) {
		return *this;
	}
	x = other.x;
	y = other.y;
	return *this;
}

bool Vector2::operator==(const Vector2& other)
{
	if(this == &other) {
		return true;
	}
	if(x == other.x && y == other.y) {
		return true;
	}
	return false;
}

Vector2& Vector2::operator+=(const Vector2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2& Vector2::operator*=(const Vector2& other)
{
	x *= other.x;
	y *= other.y;
	return *this;
}

Vector2 Vector2::operator+(const Vector2& other)
{
	Vector2 ret = *this;
	ret += other;
	return ret;
}

Vector2 Vector2::operator*(const Vector2& other)
{
	Vector2 ret = *this;
	ret *= other;
	return ret;
}


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