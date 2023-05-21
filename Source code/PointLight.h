#ifndef POINTLIGHT_H
#define POINTLIGHT_H
#include"Vector3D.h"
#include"Light.h"


class PointLight : public Light
{
public:
	Vector3D position;

	void SaveData();

	PointLight(Vector3D _position = { 0, 0, 0 }, double _intensity = 0);

	double ComputeLighting(vector<Object*> Objects, HitResult hit, Ray ray);

	~PointLight();
};
#endif
