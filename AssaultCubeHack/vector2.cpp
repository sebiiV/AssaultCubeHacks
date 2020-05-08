#include "vector2.h"


Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

float Vector2::distance(const Vector2 &vector)const {
	float dx = vector.x - x;
	float dy = vector.y - y;
	return (float)sqrt(dx * dx + dy * dy);
}
