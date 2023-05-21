#ifndef LIGHT_H
#define LIGHT_H
#include"HitResult.h"
#include"Object.h"
#include"Ray.h"
#include<windows.h>
#include<fstream>
#include<string>
using std::fstream;
using std::string;
using std::endl;
using std::ios;
using std::max;

class Light
{
public:
	string type;

	double intensity;

	virtual void SaveData() = 0;

	Light(double _intensity = 0);

	virtual double ComputeLighting(vector<Object*> Objects, HitResult hit, Ray ray) = 0;//∑µªÿπ‚«ø

	~Light();
};
#endif
