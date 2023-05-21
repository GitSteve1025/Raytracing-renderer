#ifndef RAY_H
#define RAY_H
#include"Vector3D.h"

class Ray
{
public:
	Vector3D Start;
	Vector3D Direction;

	Ray();

	Ray(Vector3D _Start, Vector3D _Direction);

	~Ray();
};
#endif
