#ifndef SPHERE_H
#define SPHERE_H
#include"Object.h"

class Sphere : public Object 
{
public:
	double R;
	Vector3D O;
	Material material;

	void SaveData();

	Sphere(double _R = 0, Vector3D _O = { 0, 0, 0 }, Material _material = { {0, 0, 0}, 0 });

	HitResult Intersect(Ray ray);

	~Sphere();
};
#endif
