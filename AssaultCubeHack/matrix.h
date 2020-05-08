#pragma once
#include <iostream>
#include "vector3.h"
#include "vector2.h"
#include "offsets.h"

class Viewmatrix
{
public:
	//     X,   Y,   Z,   W

	struct matrix {
		float m11, m12, m13, m14; //00, 01, 02, 03
		float m21, m22, m23, m24; //04, 05, 06, 07
		float m31, m32, m33, m34; //08, 09, 10, 11
		float m41, m42, m43, m44; //12, 13, 14, 15
	} matrix;

	Viewmatrix();
	bool WorldToScreen(Vector3 worldPos, int width, int height,Vector2 &targetPos);
	void debugString();
};

