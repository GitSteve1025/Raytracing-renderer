#ifndef AMBIENTLIGHT_H
#define AMBIENTLIGHT_H
#include"Light.h"

class AmbientLight : public Light
{
public:

	AmbientLight(double _intensity = 0);

	void SaveData();

	double ComputeLighting(vector<Object*> Objects, HitResult hit, Ray ray);

	~AmbientLight();
};

#endif