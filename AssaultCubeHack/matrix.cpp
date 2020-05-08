#include "matrix.h"
#include "vector3.h"

Viewmatrix::Viewmatrix(){
	this->matrix = {};
}

bool Viewmatrix::WorldToScreen(Vector3 worldPos, int width, int height, Vector2& targetPos) {

	//multiply vector against matrix
	float screenX = (matrix.m11 * worldPos.x) + (matrix.m21 * worldPos.y) + (matrix.m31 * worldPos.z) + matrix.m41;
	float screenY = (matrix.m12 * worldPos.x) + (matrix.m22 * worldPos.y) + (matrix.m32 * worldPos.z) + matrix.m42;
	float screenW = (matrix.m14 * worldPos.x) + (matrix.m24 * worldPos.y) + (matrix.m34 * worldPos.z) + matrix.m44;

	//camera position (eye level/middle of screen)
	float camX = width / 2.0;
	float camY = height / 2.0;

	//convert to homogeneous position
	float x = camX + (camX * screenX / screenW);
	float y = camY - (camY * screenY / screenW);
	Vector2 out(x, y);
	targetPos = out;

	// check if object is behind camera / off screen (not visible)
	// w = z where z is relative to the camera 
	return (screenW > 0.001f);
}

void Viewmatrix::debugString() {
	printf("viewmatrix\n");
	float* arr = (float*)&matrix;
	for (int i = 0; i < 16; i++) {
		printf("%f\n", arr[i]);
	}
	printf("\n");
}
