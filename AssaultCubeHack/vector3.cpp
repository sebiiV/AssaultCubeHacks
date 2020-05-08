#include "vector3.h"



Vector3::Vector3() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector3::distance(const Vector3 &vector) const {
	float dx = vector.x - x;
	float dy = vector.y - y;
	float dz = vector.z - y;
	return (float)sqrt(dx * dx + dy * dy + dz * dz); //don't care about very slight precision errors here
}
