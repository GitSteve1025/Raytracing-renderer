#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H
#include"Vector3D.h"
#include"Light.h"

class DirectionalLight : public Light
{
public:
	Vector3D direction;

	void SaveData();

	DirectionalLight(Vector3D _direction = { 0, 0, 0 }, double _intensity = 0);

	double ComputeLighting(vector<Object*> Objects, HitResult hit, Ray ray);

	~DirectionalLight();
};
#endif
