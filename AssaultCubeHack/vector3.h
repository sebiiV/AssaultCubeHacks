#pragma once
#include <math.h>

class Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3(float x,float y,float z);
	Vector3();

	float distance(const Vector3 &vector) const; 



};

