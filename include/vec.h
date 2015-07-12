#ifndef VEC_H
#define VEC_H

struct Vector2
{
	Vector2();
	Vector2(float _x, float _y);

	Vector2& 	operator+=(const Vector2& other);
	Vector2& 	operator*=(const Vector2& other);
	Vector2  	operator+ (const Vector2& other);
	Vector2  	operator* (const Vector2& other);
	Vector2& 	operator= (const Vector2& other);
	bool 	 	operator==(const Vector2& other);


        float x, y;
};

struct AABBCoords
{
	float x1, y1, x2, y2;
};

struct AABB
{
	Vector2 pos, dim;

	bool intersects(const AABB& other) const;
	AABBCoords coords() const;
};

#endif // VEC_H
