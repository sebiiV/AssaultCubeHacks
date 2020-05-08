#pragma once
#include <math.h>

class Vector2
{
public:
	float x;
	float y;
	Vector2(float x, float y);

	float distance(const Vector2& vector)const;
};

